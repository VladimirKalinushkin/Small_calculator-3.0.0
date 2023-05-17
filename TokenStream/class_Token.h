
class Token
{
public:

    char type = '\0';
    double value = -INFINITY;
    string word = "";

    Token() {}
    Token (string w, double v) { word = w; value = v;}
    Token (double v) { value = v; }
    Token (string w) { word = w; }

    Token get(istream &is);

};


