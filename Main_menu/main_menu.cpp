
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

        try {

            if( Main_settings.get_mode_input() == Modes_input::console || 
                Main_settings.get_mode_output_with_file() == Modes_output_with_file::on_to_console_and_file )
                cout << promt;

            Token oper = Stream.get();
            if(oper.type == exit_simbol)
                return;
            
            Stream.putback(oper);
            enable_Main_modes(Main_settings, Stream);
                
        }
        catch (MainException & ex)
        {
            ex.what();
            ex.put_to_file(file_to_log_error, Main_settings.name_file_to_error_log);
            Stream.clear();
        }


    }
    
}

void enable_Main_modes(Settings &Main_settings, TokenStream &Stream) {

    Token oper = Stream.get();

    if(oper.type == help) {
        help_out();
        return; 
    }
    else if(oper.type == settings){
        Main_settings.main_menu_to_set_all_settings();
        return;
    }
    else if(oper.type == key_word && oper.word == "from_file")
    {
        set_filestream_to_input(Main_settings);
        return;
    }
    else{ 
        Stream.putback(oper);
        enable_mode(Main_settings, Stream);
        check_correct_end_input(Stream);
    }
}

void set_filestream_to_input(Settings &Main_settings) {

    string name;
    cout << "Введите имя файла: " << promt;
    cin >> name;

    Main_settings.set_mode_input(Modes_input::file, name);
}

void check_correct_end_input(TokenStream &Stream) {
    
    Token oper = Stream.get();
    if(oper.type != print) {
        throw MainException(oper, "Выражение неправильно завершено! Нет ';' !");
    };

 }
