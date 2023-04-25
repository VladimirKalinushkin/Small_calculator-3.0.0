
#include "expression_handler.h"

void expression_handler(TokenStream &Stream){

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
    out_off_math_expression_resuilt(Stream, result);

}

void key_word_handler(TokenStream &Stream, const Token& key_word)
{

    if ( key_word.word == "var" ) 
        set_new_varriable(Stream);
    else
        throw "Пока не реализована обработка этого ключевого слова! \n";

}

void out_off_math_expression_resuilt(TokenStream &Stream, const double &result)
{

    cout
        << print_result
        << result
        << '\n';

}

