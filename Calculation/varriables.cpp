
#include "varriables.h"


void set_new_varriable(TokenStream &Stream){

    Token oper = Stream.get();
    if (oper.type == type_lexeme::word) {

        if (Stream.get().type == '=') {

            string name = oper.word;
            double value = third_order(Stream);
            Stream.inicialise_Varriable(name, value);

        }
        else throw MainException("Пропущено '=' !");

    }
    else throw MainException(oper, " Имя переменной занято!");


}

void set_Varriable(TokenStream &Stream, const Token &oper) {

    double value = third_order(Stream);
    Stream.set_Varriable( oper.word, value );


}
