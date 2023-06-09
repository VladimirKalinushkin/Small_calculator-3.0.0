
#include "expression_handler.h"

void expression_handler(TokenStream &Stream){

    Token oper = Stream.get();
    if(oper.type == type_lexeme::key_word)
    {
        key_word_handler(Stream, oper);
        return;
    }    

    if(oper.type == type_lexeme::varriable)
    {
        Token new_oper = Stream.get();
        if( new_oper.type == '=')
        {
            set_Varriable(Stream, oper);
            return;
        }
        else 
            Stream.putback(new_oper);
    }

    Stream.putback(oper);
    double result = third_order(Stream);
    out_off_math_expression_resuilt(Stream, result);

}

void key_word_handler(TokenStream &Stream, const Token& key_word)
{

    if ( key_word.word == "var" ) 
        set_new_varriable(Stream);
    else
        throw MainException(key_word, "Пока не реализована обработка этого ключевого слова!");

}

void out_off_math_expression_resuilt(TokenStream &Stream, const double &result)
{

    if( 

        Main_settings.get_mode_input() == Modes_input::file ||
        Main_settings.get_mode_output() == Modes_output::to_file ||
        Main_settings.get_mode_output() == Modes_output::to_console_and_file

    ) {

        ofstream ofs("output.txt", ios::app);
        Chrono::Date _now;
        Chrono::Time _now_tm;
        ofs << '\t' << _now << ' ' << _now_tm << ' '<< " - " << result << '\n';
        ofs.close();

    }

    if( 

        Main_settings.get_mode_input() == Modes_input::console && (
            Main_settings.get_mode_output() == Modes_output::to_console ||
            Main_settings.get_mode_output() == Modes_output::to_console_and_file
        ) ||
        (
            Main_settings.get_mode_input() == Modes_input::file &&
            Main_settings.get_mode_output_file() == Modes_output_with_file::on_to_console_and_file
        )

    ) {

        cout
            << print_result
            << result
            << '\n';

    }
}

