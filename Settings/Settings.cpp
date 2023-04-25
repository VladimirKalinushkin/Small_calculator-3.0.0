
#include "Settings.h"


Settings::Settings()
{

    _mode_calculating = Modes_calculating::arabian;
    
}

void Settings::set_all_settings()
{
    try{

        set_Mode_calculating();

    }
    catch(exeption & ex)
    {
        ex.what();
    }
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
        throw exeption("Неправильный ввод!\n");

    };
}


Settings::exeption::exeption(char *msg)
{
    message = msg;
}

void Settings::exeption::what()
{

    if (message)
        cerr << message << "\n";
}
