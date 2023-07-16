
class TokenStream {

public:

    TokenStream( const map <string,
                 double> &constantes,
                 const set <string> &key_vords,
                 const set <string> &mathematic_functions,
                 Settings &settings
                );

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

    ifstream _file_for_input;
    
    void inicialiseStream(const map <string, double> &constantes, const set <string> &key_vords, const set <string> &mathematic_functions);
    
    Token set_Token_type(const Token &buffer);
    
    Token get_new_Token();
    Token read_Token(istream &is);
    void open_or_close_file_with_end();

};

void check_error_and_close_file(ifstream &_file_for_input, Settings &Main_settings);
