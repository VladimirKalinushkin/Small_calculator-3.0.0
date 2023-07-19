
#pragma once
#include "Settings.h"


Settings::Settings()
{

    _mode_calculating = Modes_calculating::arabian;
    _mode_input = Modes_input::console;
    _mode_output =  Modes_output ::to_console;
    _mode_output_with_file = Modes_output_with_file::on_to_console_and_file;
    _name_file_to_output = "output.txt";
    
}

void Settings::main_menu_to_set_all_settings() {
    
    while (cin) {

        cout << "Для настройки режима вычислений введите c, "
             << "для настройки вывода файла - o, "
             << "для режима вывода при вводе из файла - f, "
             << "чтобы указать имя файла для вывода - n, "
             << "для выхода - e: "
             << '\n'
             << PROMT;
             
        char ch;
        cin >> ch;

        if(ch == 'c')
            set_mode_calculating();

        else if(ch == 'o')
            set_mode_output();

        else if(ch == 'f')
            set_mode_output_with_file();

        else if(ch == 'n')
            set_name_file_to_output();

        else if(ch == 'e')
            return;

        else {
            cout << "Неправильный ввод!\n";
            return;
        }

    }

}

void Settings::set_mode_calculating()
{
    
    cout << "Введите режим работы вычислений (полный режим с арабскими числами или ограниченный - с римскими): " 
         << char(Modes_calculating::arabian) << " / " << char (Modes_calculating::roman) 
         << '\n' << PROMT;
    
    char mode;
    cin >> mode;

    switch(mode){

    case Modes_calculating::arabian:
    case Modes_calculating::roman:
        _mode_calculating = Modes_calculating(mode);
        break;

    default:
        throw MainException("Неправильный ввод!\n");

    };

}

void Settings::set_mode_output() {

    cout << "Введите режим вывода (только в консоль, в консоль и в файл, или только в файл): " 
         << char(Modes_output::to_console) << " / " << char (Modes_output::to_console_and_file) << " / " << char(Modes_output::to_file)
         << '\n' << PROMT;
    
    char mode;
    cin >> mode;

    switch(mode){

    case Modes_output::to_console:
    case Modes_output::to_console_and_file:
    case Modes_output::to_file:
        _mode_output = Modes_output(mode);
        return;
        break;

    default:
        throw MainException("Неправильный ввод!\n");

    };

}
void Settings::set_mode_output_with_file() {

    cout << "Введите режим вывода при вводе из файла (в консоль и файл или только в файл): " 
         << char(Modes_output_with_file::on_to_console_and_file) << " / " << char (Modes_output_with_file::on_to_file)
         << '\n' << PROMT;
    
    char mode;
    cin >> mode;

    switch(mode){

    case Modes_output_with_file::on_to_console_and_file:
    case Modes_output_with_file::on_to_file:
        _mode_output_with_file = Modes_output_with_file(mode);
        return;
        break;

    default:
        throw MainException("Неправильный ввод!\n");

    };

}

void Settings::set_name_file_to_output() {

    string name;
    cout << "Введите имя файла: \n" << PROMT;
    cin >> name;

    _name_file_to_output = name;


}

bool Settings::promt_must_otput() {

    return ( _mode_input == Modes_input::console || 
        _mode_output_with_file == Modes_output_with_file::on_to_console_and_file );
}
bool Settings::output_is_to_file() {

    return ( 
        _mode_input == Modes_input::file ||
        _mode_output == Modes_output::to_file ||
        _mode_output == Modes_output::to_console_and_file 
    );
}
bool Settings::output_is_to_console() {
    
    return ( 
        _mode_input == Modes_input::console && (
            _mode_output == Modes_output::to_console ||
            _mode_output == Modes_output::to_console_and_file ) ||  
        (
            _mode_input == Modes_input::file &&
            _mode_output_with_file == Modes_output_with_file::on_to_console_and_file 
        )
    );
}

