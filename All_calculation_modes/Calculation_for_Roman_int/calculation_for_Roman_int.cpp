
#pragma once
#include "calculation_for_Roman_int.h"


void expression_handler_for_Roman_int(Settings &Main_settings, TokenStream &Stream)
{

    try
    {
        Roman_int result = third_order_for_Roman_int(Stream);

        out_math_expression_s_result(Main_settings, result);

    }
    catch(Roman_int::exeption ex)
    {
        ex.what();
    }

}

Roman_int third_order_for_Roman_int(TokenStream &Stream)
{
    Roman_int value = second_order_for_Roman_int(Stream);

    while (cin) {

        Token oper = Stream.get();
        
        switch (oper.type) {
            case '+':{
                Roman_int second_value = second_order_for_Roman_int(Stream);
                value += second_value;
                break;}
            case '-':{
                Roman_int second_value = second_order_for_Roman_int(Stream);
                value -= second_value;
                break;}
            default:{
                Stream.putback(oper);
                return value;
                break;}
        }
    }

    return value;
}

Roman_int second_order_for_Roman_int(TokenStream &Stream)
{
    Roman_int value = primary_for_Roman_int(Stream);

    while (cin) {

        Token oper = Stream.get();
        
        switch (oper.type) {
            case '*':{
                Roman_int second_value = primary_for_Roman_int(Stream);
                value *= second_value;
                break;}
            case '/':{
                Roman_int second_value = primary_for_Roman_int(Stream);
                value /= second_value;
                break;}
            default:{
                Stream.putback(oper);
                return value;
                break;}
        }
    }

    return value;
}

Roman_int primary_for_Roman_int(TokenStream &Stream)
{
    Token oper = Stream.get();
    Roman_int ret;

    switch (oper.type) {

        case type_lexeme::word:{

            ret.set(oper.word);
            if(ret.empty())
                throw MainException(oper, "Неправильный ввод!");

            return ret;
            break;

        }
        case '+':{

            return primary_for_Roman_int(Stream);
            break;
            
        }
        case '(':{

            Roman_int result = third_order_for_Roman_int(Stream);

            oper = Stream.get();
            if (oper.type != ')')
                throw MainException(oper, "нет ')' !");

            return result;
            break;

        }
        default:{

            throw MainException(oper, "Нет первичного выражения!");
            break;
        
        }
    }

}