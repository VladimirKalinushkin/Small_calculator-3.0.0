
#pragma once
#include "main_menu.h"


void main_menu(Settings &Main_settings, TokenStream &Stream) {

    while (cin) {

        try {

            if(Main_settings.promt_must_otput())
                cout << PROMT;

            if(Main_settings.get_mode_input() == Modes_input::console && check_exit_simbol(Stream)) 
                return;

            if(Main_settings.get_mode_input() == Modes_input::console && enable_Main_modes(Main_settings, Stream))
                continue;
            
            Mathematic_result result;
            enable_Mathematic_modes(Stream, Main_settings, result);
            result.out_math_expression_s_result(Main_settings);

            check_correct_end_input(Stream);
            
        }
        catch (MainException &ex) {

            errors_handler(ex, Main_settings);
            
        }
    }
} 

bool check_exit_simbol(TokenStream &Stream) {

    Token oper = Stream.get();
    if(oper.type == exit_simbol)
        return true;
    
    Stream.putback(oper);
    return false;

}
bool enable_Main_modes(Settings &Main_settings, TokenStream &Stream) {
    
    Token oper = Stream.get();

    if(oper.type == help) {
        help_out();
        return true; 
    }
    else if(oper.type == settings) {
        Main_settings.main_menu_to_set_all_settings();
        return true;
    }
    else if(oper.type == key_word && oper.word == "from_file") {
        set_filestream_to_input(Main_settings);
        return true;
    }
    else
        Stream.putback(oper);
    
    return false;

}

void set_filestream_to_input(Settings &Main_settings) {

    string name;
    cout << "Введите имя файла: " << PROMT;
    cin >> name;

    Main_settings.set_mode_input(Modes_input::file, name);
}
void check_correct_end_input(TokenStream &Stream) {
    
    Token oper = Stream.get();
    if(oper.type != print) {
        throw MainException(oper, "Выражение неправильно завершено! Нет ';' !");
    };

}

void errors_handler(MainException &ex, Settings &Main_settings) {

    ex.what();
    Stream.clear();

    ofstream file_to_output_log(Main_settings.name_file_to_error_log, ios::app);

    if (file_to_output_log.is_open()) {
        ex.put_to_file(file_to_output_log);
        file_to_output_log.close();
    }
    else
        cerr << "Не удалось открыть файл вывода лога! \n";

    file_to_output_log.close();
    
}
