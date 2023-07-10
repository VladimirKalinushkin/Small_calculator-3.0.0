
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

    if(Main_settings.get_mode_input() == Modes_input::file && Stream._file_for_input) {
        double result = get_delay_with_calculating_from_file(Stream);
        out_math_expression_s_result(Main_settings, result);

    }
    else
        out_math_expression_s_result(Main_settings, third_order(Stream));

}

void key_word_handler(TokenStream &Stream, const Token& key_word)
{

    if ( key_word.word == "var" ) 
        set_new_varriable(Stream);
    else
        throw MainException(key_word, "Пока не реализована обработка этого ключевого слова!");

}

double get_delay_with_calculating_from_file(TokenStream &Stream) {

    bool &end = Graphick_delay_must_be_end = true;
    if(end == true)
        end = false;
    else
        return third_order(Stream);
        
    MainException ex; bool is_error = false;
    double result;

    thread th([&ex, &is_error, &end, &Stream, &result]() { 
        try {

            result = third_order(Stream);

        }
        catch(MainException &_ex) {
            is_error = true;
            ex = _ex;
        }
        
        end = true;
    } );

    th.detach();
    Delay_indicator(end);

    if(is_error)
        throw MainException(ex);

    return result;

}

