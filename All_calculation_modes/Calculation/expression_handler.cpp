
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
    double result = third_order(Stream);
    out_math_expression_s_result(Main_settings, Stream, result);

}

void key_word_handler(TokenStream &Stream, const Token& key_word)
{

    if ( key_word.word == "var" ) 
        set_new_varriable(Stream);
    else
        throw MainException(key_word, "Пока не реализована обработка этого ключевого слова!");

}

