
#include "main_menu.h"



void welcome_words() {
    cout
        << "Введите выражение, завершите его "
        << ';'
        << " . Для выхода введите "
        << exit_simbol
        << ", для прочих вопросов введите "
        << help
        << ", для настроек - "
        << settings
        << '\n'
        << '\n';
}

void main_menu(Settings &Main_settings, TokenStream &Stream) {

    while (cin) {
        cout << promt;
        try {

            Token oper = Stream.get();

            switch (oper.type) {

                case exit_simbol: 
                    return;
                    break;

                case help: 
                    help_out();
                    continue;
                    break;

                case settings:
                    Main_settings.set_all_settings();
                    continue;
                    break;

                default: 
                    Stream.putback(oper);
                    enable_mode(Main_settings, Stream);
                    check_correct_end_input(Stream);
                    break;
                
            }

        }

        catch (TokenStream::exeption& ex) {
            ex.what();
            Stream.clear();
            cin.clear();
            cin.ignore(1000, '\n');
        }
        catch (MainException & ex)
        {
            ex.what();
            ex.put_to_file(file_to_log_error, Main_settings);
            Stream.clear();
            cin.clear();
            cin.ignore(1000, '\n');
        }


    }
    
}

void check_correct_end_input(TokenStream &Stream) {
    
    Token oper = Stream.get();
    if(oper.type != print) {
        throw MainException(oper, "Выражение неправильно завершено! Нет ';' !");
    };

}
