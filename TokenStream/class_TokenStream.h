
class TokenStream {

public:

    TokenStream( const map <string,
                 double> &constantes,
                 const set <string> &key_vords,
                 const set <string> &mathematic_functions,
                 Settings &settings,
                 ifstream &file_for_input
                );

    Token get();
    void putback(Token buffer);

    void clear();

    void inicialise_Varriable(const string &s, const double &value);
    void set_Varriable(const string &s, const double &value);

    Settings *Main_settings;
    ifstream *_file_for_input;

private:

    vector <Token> Stream;
    vector <Token> ConstantesStream;
    vector <Token> KeyWordsStream;
    vector <Token> FunctionsNameStream;
    vector <Token> VarriablesStream;

    Token get_new_Token();
    
    Token set_Token_type(const Token &buffer);
    void inicialiseStream(const map <string, double> &constantes, const set <string> &key_vords, const set <string> &mathematic_functions);

};

Token read_Token(istream &is);
