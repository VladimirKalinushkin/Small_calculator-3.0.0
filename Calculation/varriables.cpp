
#include "varriables.h"


void set_new_varriable(TokenStream &Stream){

    Token name = Stream.get();
    if (name.type == type_lexeme::word) {

        if (Stream.get().type == '=') {

            double value = third_order(Stream);
            Stream.inicialise_Varriable(name.word, value);

        }
        else throw TokenStream::exeption("Пропущено '=' !");

    }
    else throw TokenStream::exeption(" Имя переменной занято!");


}

void set_Varriable(TokenStream &Stream, const Token &oper) {

    double value = third_order(Stream);
    Stream.set_Varriable( oper.word, value );


}
