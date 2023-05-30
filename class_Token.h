
class Token
{
public:

    char type = '\0';
    double value = -INFINITY;
    string word = "";

    Token() {}
    Token (string w, double v) {type = type_lexeme::constante; word = w; value = v;}
    Token (double v) { type = type_lexeme::number; value = v; }
    Token (string w) { type = type_lexeme::word; word = w; }

};


