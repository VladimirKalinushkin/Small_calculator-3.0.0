
class TokenStream {

public:

    TokenStream(const map <string, double> &constantes, const set <string> &key_vords, const set <string> &mathematic_functions);

    Token get();
    void putback(Token buffer);

    void clear();

    void inicialise_Varriable(const string &s, const double &value);
    void set_Varriable(const string &s, const double &value);
    class exeption : public exception {
        public:
            exeption(char *msg);
            void what(); 
        private:
            char *message = NULL;
            char *bad_value_string = NULL;
    };

private:

    vector <Token> Stream;
    vector <Token> ConstantesStream;
    vector <Token> KeyWordsStream;
    vector <Token> FunctionsNameStream;
    vector <Token> VarriablesStream;

    Token set_Token_type(const Token &buffer);
    void inicialiseStream(const map <string, double> &constantes, const set <string> &key_vords, const set <string> &mathematic_functions);

};


