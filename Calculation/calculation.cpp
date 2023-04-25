
#include "calculation.h"

double third_order(TokenStream &Stream) {

    double value = second_order(Stream);

    while (cin) {

        Token oper = Stream.get();
        switch (oper.type) {
            case '+':{
                value += second_order(Stream);
                break;}
            case '-':{
                value -= second_order(Stream);
                break;}
            default:{
                Stream.putback(oper);
                return value;
                break;}
        }
    }

    return 0;

}

double second_order(TokenStream &Stream) {

    double value = first_order(Stream);

    while (cin) {

        Token oper = Stream.get();

        switch (oper.type) {
            case '*':{
                value *= first_order(Stream);
                break;}
            case '/':{
                double second_value = first_order(Stream);
                if (second_value == 0)
                    throw " Деление на нуль! \n";
                value /= second_value;
                break;}
            default:{
                Stream.putback(oper);
                return value;
                break;}
        }
    

    }
    return 0;

}

double first_order(TokenStream &Stream) {

    double value = primary(Stream);

    while (cin) {

        Token oper = Stream.get();
        if (oper.type == '^') {
            double second_value = primary(Stream);
            value = pow (value, second_value);
        }
        else {
            Stream.putback(oper);
            return value;
        }
    }

    return 0;

}

double primary(TokenStream &Stream) {

    Token oper = Stream.get();

    switch (oper.type) {

        case type_lexeme::constante:
        case type_lexeme::number:
        case type_lexeme::varriable:{

            return oper.value;
            break;

        }
        case '+':{
            return primary(Stream);
            break;}
        case '-':{
            return  -primary(Stream);
            break;}
        case '(':{

            double result = third_order(Stream);
            oper = Stream.get();
            if (oper.type != ')') throw "нет ')' \n";
            else return result;
            break;

        }
        case type_lexeme::function:{
            Stream.putback(oper);
            return math_function(Stream);
            break;
        }
        case type_lexeme::word: {
            throw " Переменная не инициализирована! \n";
            break;}
        case type_lexeme::key_word: {
            throw " Имя занято! \n";
            break;}
        default:{
            throw " Нет первичного выражения! \n";
            break;}
    }

    return 0;
}

double math_function(TokenStream &Stream) {

    string name = Stream.get().word;

    if (name == "fmod") return instead_of_reading_fmod_calculation(Stream);

    double result = primary(Stream);
    
    if (name == "abs") return abs ( result );
    else if (name == "ln") return log ( result );
    else if (name == "log") return log10 ( result );
    else if (name == "ceil") return ceil ( result );
    else if (name == "floor") return floor (result );
    else if (name == "cos") return cos ( result );
    else if (name == "sin") return sin ( result );
    else if (name == "tan") return tan ( result );

    if (name == "sqrt" )
        if(result >= 0)
            return sqrt ( result );
        else
            throw " Корень можно извлечь только из неотрицательного числа! \n";
    
    if (result < -1 & result > 1)
        throw "Для обратных тригонометрических функций должно испооьзоваться значение от -1 до 1! \n";

    if (name == "asin") return asin ( result );
    else if (name == "acos") return acos ( result );
    else if (name == "atan") return atan ( result );

    throw "Неизвестная функция, ошибка в логике программы! \n";

}

double instead_of_reading_fmod_calculation(TokenStream &Stream)
{
        
        char left_bracket = Stream.get().type;
        if(left_bracket != '(')
            throw "Нет открывающей скобки!\n";

        double left = primary(Stream);

        char punkt = Stream.get().type;
        if(punkt != ',')
            throw "Пропущена запятая!\n";

        double right = primary(Stream);

        if ( right == 0 )
            throw "Деление на нуль!\n";

        char right_bracket = Stream.get().type;
        if(right_bracket != ')')
            throw "Нет закрывающей скобки!\n";

        return fmod ( left, right );

}
