
#include "varriables.h"


void set_new_varriable(TokenStream &Stream){

    Token name = Stream.get();
    if (name.type == type_lexeme::word) {

        if (Stream.get().type == '=') {

            double value = third_order(Stream);
            Stream.inicialise_Varriable(name.word, value);

        }
        else throw "Пропущено '=' \n";

    }
    else throw " Имя переменной занято! \n";


}

void set_Varriable(TokenStream &Stream, const Token &oper) {

    double value = third_order(Stream);
    Stream.set_Varriable( oper.word, value );


}
