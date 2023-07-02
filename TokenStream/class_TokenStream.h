
class TokenStream {

public:

    TokenStream( const map <string,
                 double> &constantes,
                 const set <string> &key_vords,
                 const set <string> &mathematic_functions,
                 Settings &settings,
                 ifstream &file_to_input
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

void open_or_close_file_for_input(ifstream &_file_for_input, Settings &Main_settings);
void throw_new_Main_exception_with_error_input_from_file(ifstream &_file_for_input);
void close_file_input_with_error(ifstream &_file_for_input, Settings &Main_settings);
