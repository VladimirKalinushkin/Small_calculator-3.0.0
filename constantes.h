
const char* print_result = ": ";
const char* promt = ">> ";

const char exit_simbol = 'q';
const char help = '?';
const char settings = '>';
const char print = ';';
const char equality = '=';
const set <char> Main_modes_simbols = {
    exit_simbol,
    help,
    settings,
    print,
    equality,
    '-', 
    '+',
    '*',
    '/', 
    '(',
    ')', 
    '^', 
    ','
};

enum type_lexeme{

    number = 'n',
    word = 'w',
    constante = 'c',
    key_word = 'k',
    varriable = 'v',
    function = 'f'

};

const map <string, double> constantes = {

    {"pi", 3.14159265}, 
    {"e", 2.71828}

    };
const set <string> key_vords = {

    "var"

};
const set <string> mathematic_functions = {

    "cos", 
    "sin", 
    "tan", 
    "asin", 
    "acos", 
    "atan", 
    "sqrt", 
    "abs", 
    "ln", 
    "log", 
    "ceil", 
    "fmod", 
    "fmod"

};

enum Modes_calculating {

    arabian = 'a',
    roman = 'r'

};
