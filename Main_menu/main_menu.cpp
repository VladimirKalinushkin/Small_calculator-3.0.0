
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

        catch (const char* msg) { 
            error (msg);
            Stream.clear();
        }


    }
    
}

void check_correct_end_input(TokenStream &Stream) {
    
    if(Stream.get().type != print) {
        throw " Выражение неправильно завершено! Нет ';' \n";
    };

}
