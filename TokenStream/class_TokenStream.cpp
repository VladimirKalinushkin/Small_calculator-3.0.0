

#pragma once
#include "class_TokenStream.h"


TokenStream::TokenStream(   const map <string, 
                            double> &constantes, 
                            const set <string> &key_vords, 
                            const set <string> &mathematic_functions, 
                            Settings &settings,
                            ifstream &file_for_input) {

    inicialiseStream(constantes, key_vords, mathematic_functions);
    Main_settings = &settings;
    _file_for_input = &file_for_input;

}

Token TokenStream::get() {

    Token buffer;

    if(Stream.size()) {

        buffer = Stream.back();
        Stream.pop_back();
        return buffer;

    }
    else {

        buffer = get_new_Token();
        
        if (buffer.type == type_lexeme::word) return set_Token_type(buffer);

        return buffer;

    }

}
Token TokenStream::get_new_Token() {

    Token buffer;


    if(Main_settings->get_mode_input() == Modes_input::console) {
        buffer = read_Token(cin);
        return buffer;
    }
    
    else if(Main_settings->get_mode_input() == Modes_input::file && !_file_for_input->is_open())
        _file_for_input->open(Main_settings->get_name_file_to_input());

    if( _file_for_input->fail() || _file_for_input->bad() ||
        _file_for_input->eof() || _file_for_input->peek() == EOF) {
            Main_settings->set_mode_input(Modes_input::console);
            _file_for_input->close();
    }

    if(_file_for_input->fail())
        throw MainException("Невозможно открыть файл!");
    else if(_file_for_input->bad())
        throw MainException("Ошибка при чтении файла!");
    else if(_file_for_input->eof() || _file_for_input->peek() == EOF)
        throw MainException("Файл успешно считан!");

    try {
        
        if(*_file_for_input) {
            buffer = read_Token(*_file_for_input);
            return buffer;
        }
        
    }
    catch(const char* msg) {
        _file_for_input->close();
        Main_settings->set_mode_input(Modes_input::console);
        throw MainException(msg);
    }


}

void TokenStream::putback(Token buffer) {

    Stream.push_back(buffer);

}

void TokenStream::clear() {

    Stream.clear();

    if(Main_settings->get_mode_input() == Modes_input::file)
        clear_istream(*_file_for_input);
    else
        clear_istream(cin);
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

    throw MainException(("Неизвестная переменная!"));

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


Token read_Token(istream &is) {

    Token ret;

    is >> ret.type;

    if (Main_modes_simbols.count(ret.type))
        return ret;

    else if (isdigit(ret.type))
    {
        is.putback(ret.type);
        is >> ret.value;
        ret.type = type_lexeme::number;
        return ret;
    }

    else if (isalpha(ret.type))
    {
        is.putback(ret.type);
        ret.word = get_word_from_string(is);
        ret.type = type_lexeme::word;
        return ret;
    }
    
    else if(!is && is.peek() == EOF) 
        throw "Конец файла!";
    
    else
        throw MainException(ret, "Неправильный ввод!");

}

