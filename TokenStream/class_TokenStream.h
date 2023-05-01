
class TokenStream {

public:

    TokenStream(const map <string,
                 double> &constantes,
                 const set <string> &key_vords,
                 const set <string> &mathematic_functions,
                 Settings &settings);

    Token get();
    void putback(Token buffer);

    void clear();

    void inicialise_Varriable(const string &s, const double &value);
    void set_Varriable(const string &s, const double &value);

    Settings *Main_settings;

private:

    vector <Token> Stream;
    vector <Token> ConstantesStream;
    vector <Token> KeyWordsStream;
    vector <Token> FunctionsNameStream;
    vector <Token> VarriablesStream;

    ifstream file_for_input;
    
    Token set_Token_type(const Token &buffer);
    void inicialiseStream(const map <string, double> &constantes, const set <string> &key_vords, const set <string> &mathematic_functions);

public:

    class exeption : public exception {
        public:
            exeption(char *msg);
            void what(); 
        private:
            char *message = NULL;
    };
};


