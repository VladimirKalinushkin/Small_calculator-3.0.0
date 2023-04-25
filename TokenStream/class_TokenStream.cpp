
#include "class_TokenStream.h"


TokenStream::TokenStream(const map <string, double> &constantes, const set <string> &key_vords, const set <string> &mathematic_functions) {

    inicialiseStream(constantes, key_vords, mathematic_functions);

}

Token TokenStream::get() {

    if(Stream.size()) {

        Token buffer = Stream.back();
        Stream.pop_back();

        return buffer;

    }
    else {

        Token buffer = buffer.get();

        if (buffer.type == type_lexeme::word) return set_Token_type(buffer);

        return buffer;

    }

}
void TokenStream::putback(Token buffer) {

    Stream.push_back(buffer);

}

void TokenStream::clear() {

    Stream.clear();

}

Token TokenStream::set_Token_type(const Token &buffer) {

    string s = buffer.word;
    
    for(auto t : ConstantesStream)
    {
        if(t.word == s)
            return t;
    }
    
    for(auto t : KeyWordsStream)
    {
        if(t.word == s)
            return t;
    }
    
    for(auto t : FunctionsNameStream)
    {
        if(t.word == s)
            return t;
    }

    for(auto t : VarriablesStream)
    {
        if(t.word == s)
            return t;
    }
    return buffer;

}

void TokenStream::inicialise_Varriable(const string &s, const double &value){

    Token new_Varriable(s, value);
    new_Varriable.type = type_lexeme::varriable;
    VarriablesStream.push_back(new_Varriable);

}
void TokenStream::set_Varriable(const string &s, const double &value) {

    for(int i = 0; i < VarriablesStream.size(); i++)
    {
        if(VarriablesStream[i].word == s)
        {
            VarriablesStream[i].value = value;
            return;
        }
    }

    throw " Неизвестная переменная! \n";

}


void TokenStream::inicialiseStream(const map <string, double> &constantes, const set <string> &key_vords, const set <string> &mathematic_functions){

    for(auto c : constantes)
    {
        Token T(c.first, c.second);
        T.type = type_lexeme::constante;
        ConstantesStream.push_back(T);
    }

    for(auto k : key_vords)
    {
        Token T(k);
        T.type = type_lexeme::key_word;
        KeyWordsStream.push_back(T);
    }

    for(auto m : mathematic_functions)
    {
        Token T(m);
        T.type = type_lexeme::function;
        ConstantesStream.push_back(T);
    }

}

