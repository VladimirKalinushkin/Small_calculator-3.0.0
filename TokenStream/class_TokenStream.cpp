

TokenStream::TokenStream(const map <string,
                         double> &constantes, const set <string> &key_vords, 
                         const set <string> &mathematic_functions, 
                         Settings &settings) {

    inicialiseStream(constantes, key_vords, mathematic_functions);
    Main_settings = &settings;

}

Token TokenStream::get() {

    Token buffer;

    if(Stream.size()) {

        buffer = Stream.back();
        Stream.pop_back();

        return buffer;

    }
    else {

        if(Main_settings->get_mode_input() == Modes_input::console)
            buffer.get(cin);
        else if(Main_settings->get_mode_input() == Modes_input::file) {
            file_for_input.open(Main_settings->get_name_file_to_input());
            if(file_for_input.good())
                buffer.get(file_for_input);
            else {
                Main_settings->set_mode_input(Modes_input::console);
                throw exeption("Невозможно открыть файл! Ввод будет произволиться из консоли!");
            }
        }

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

    throw exeption(("Неизвестная переменная!"));

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

TokenStream::exeption::exeption(char *msg) {

    message = msg;
}
void TokenStream::exeption::what() {

    if (message)
        cerr << message << "\n";
}

