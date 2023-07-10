
#pragma once
#include "expression_handler.h"

void expression_handler(Settings &Main_Settings, TokenStream &Stream){

    Token oper = Stream.get();

    if(oper.type == type_lexeme::key_word)
    {
        key_word_handler(Stream, oper);
        return;
    }    

    if(oper.type == type_lexeme::varriable)
    {
        Token new_oper = Stream.get();
        if( new_oper.type == '=')
        {
            set_Varriable(Stream, oper);
            return;
        }
        else 
            Stream.putback(new_oper);
    }

    Stream.putback(oper);

    double result = calculating_or_get_delay(Main_Settings, Stream);
    out_math_expression_s_result(Main_settings, result);

}

void key_word_handler(TokenStream &Stream, const Token& key_word)
{

    if ( key_word.word == "var" ) 
        set_new_varriable(Stream);
    else
        throw MainException(key_word, "Пока не реализована обработка этого ключевого слова!");

}

double calculating_or_get_delay(Settings &Main_Settings, TokenStream &Stream) {

    bool end = false;
    double result;

    if(Main_settings.get_mode_input() == Modes_input::file && Stream._file_for_input)
    {  
        thread th([&end]()
            { Delay_indicator(end);});

        result = third_order(Stream);

        end = true;
        th.join();
    }  
    else            
        result = third_order(Stream);

    return result;

}

