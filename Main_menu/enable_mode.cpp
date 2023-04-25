
#include "enable_mode.h"


void enable_mode(Settings & Main_settings, TokenStream &Stream)
{

    switch(Main_settings.get_mode())
    {
        case Modes_calculating::arabian:
            expression_handler(Stream);
            break;
        case Modes_calculating::roman:
            expression_handler_for_Roman_int(Stream);
            break;
        default:
            throw "Не установлен режим работы!\n";
            break;
    }

}

