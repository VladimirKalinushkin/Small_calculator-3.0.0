
#include "class_Token.h"

Token Token::get(){

    Token ret;
    cin >> ret.type;

    if(Main_modes_simbols.count(ret.type))
        return ret;
        
    else if(isdigit(ret.type))  
        return get_number_lexeme_from_istream(ret.type);

    else if( isalpha(ret.type) )
        return get_word_lexeme_from_istream(ret.type);

    else
        throw " Неправильный ввод! \n";
        

}

Token get_number_lexeme_from_istream(const char &putbacked_simbol)
{
    Token ret;
    ret.type = type_lexeme::number;
    
    cin.putback(putbacked_simbol);
    cin >> ret.value;

    return ret;

}
Token get_word_lexeme_from_istream(const char &putbacked_simbol)
{
    Token ret;
    ret.type = type_lexeme::word;

    cin.putback(putbacked_simbol);

    ret.word = get_word_from_string();

    return ret;

}


