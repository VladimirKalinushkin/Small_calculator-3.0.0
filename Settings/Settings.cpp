
#include "Settings.h"


Settings::Settings()
{

    _mode_calculating = Modes_calculating::arabian;
    _mode_input = Modes_input::console;
    _mode_output =  Modes_output ::to_console;
    _mode_output_file = Modes_output_with_file::on_to_console_and_file;
    
}

void Settings::set_all_settings()
{
 
    set_Mode_calculating();
    set_Mode_output();
    set_Mode_output_file();

}

void Settings::set_Mode_calculating()
{
    
    cout << "Введите режим работы вычислений (полный режим с арабскими числами или ограниченный - с римскими): " 
         << char(Modes_calculating::arabian) << " / " << char (Modes_calculating::roman) 
         << '\n' << promt;
    
    _mode_calculating = get_Mode_calculating(); 

}
Modes_calculating Settings::get_Mode_calculating()
{


    char mode;
    cin >> mode;

    switch(mode){

    case Modes_calculating::arabian:
    case Modes_calculating::roman:
        return Modes_calculating(mode);
        break;

    default:
        throw MainException("Неправильный ввод!\n");

    };
}

void Settings::set_Mode_output() {

    cout << "Введите режим вывода (только в консоль, в консоль и в файл, или только в файл): " 
         << char(Modes_output::to_console) << " / " << char (Modes_output::to_console_and_file) << " / " << char(Modes_output::to_file)
         << '\n' << promt;
    
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
void Settings::set_Mode_output_file() {

    cout << "Введите режим вывода при вводе из файла (в консоль и файл или только в файл): " 
         << char(Modes_output_with_file::on_to_console_and_file) << " / " << char (Modes_output_with_file::on_to_file)
         << '\n' << promt;
    
    char mode;
    cin >> mode;

    switch(mode){

    case Modes_output_with_file::on_to_console_and_file:
    case Modes_output_with_file::on_to_file:
        _mode_output_file = Modes_output_with_file(mode);
        return;
        break;

    default:
        throw MainException("Неправильный ввод!\n");

    };

}
