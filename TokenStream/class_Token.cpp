

Token Token::get(istream &is)
{

    is >> this->type;

    if (Main_modes_simbols.count(this->type))
        return *this;

    else if (isdigit(this->type))
    {
        is.putback(this->type);
        is >> this->value;
        this->type = type_lexeme::number;
        return *this;
    }

    else if (isalpha(this->type))
    {
        is.putback(this->type);
        this->word = get_word_from_string(is);
        this->type = type_lexeme::word;
        return *this;
    }
    
    else if(!is && this->type == '\0')
        throw TokenStream::exeption("Конец файла!");

    else
        throw TokenStream::exeption("Неправильный ввод!");
}

