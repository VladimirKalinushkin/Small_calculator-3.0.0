

Token Token::get(istream &is)
{

    Token ret;
    is >> ret.type;

    if (Main_modes_simbols.count(ret.type))
        return ret;

    else if (isdigit(ret.type))
    {
        is.putback(ret.type);
        is >> ret.value;
        ret.type = type_lexeme::number;
        return ret;
    }

    else if (isalpha(ret.type))
    {
        is.putback(ret.type);
        ret.word = get_word_from_string(cin);
        ret.type = type_lexeme::word;
        return ret;
    }

    else
        throw TokenStream::exeption("Неправильный ввод!");
}

