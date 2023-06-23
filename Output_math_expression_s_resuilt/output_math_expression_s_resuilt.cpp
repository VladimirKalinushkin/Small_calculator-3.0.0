
#pragma once
#include "output_math_expression_s_resuilt.h"


void out_math_expression_s_result(Settings & Main_Settings, TokenStream &Stream, const double &result) {

    if( output_is_to_file(Main_Settings) )
        output_result_to_file(*Stream._file_to_output, Main_Settings.get_name_file_to_output(), result); 

    if(output_is_to_console(Main_settings) ) 
        output_resuilt_to_console(result);

}
void output_result_to_file(ofstream &file_to_output, string name, const double &result) {

    file_to_output.open(name, ios::app);

    Chrono::Date _now;
    Chrono::Time _now_time;

    file_to_output << '\t' << _now << ' ' << _now_time << ' '<< " - " << result << '\n';

    file_to_output.close();

}
void output_resuilt_to_console(const double &result) {

    cout
        << print_result
        << result
        << '\n';

}

void out_math_expression_s_result(Settings & Main_Settings, TokenStream &Stream, const Roman_int &result) {

    if( output_is_to_file(Main_Settings) )
        output_result_to_file(*Stream._file_to_output, Main_Settings.get_name_file_to_output(), result); 

    if(output_is_to_console(Main_settings) ) 
        output_resuilt_to_console(result);

}
void output_result_to_file(ofstream &file_to_output, string name, const Roman_int &result) {

    file_to_output.open(name, ios::app);

    Chrono::Date _now;
    Chrono::Time _now_time;
    Roman_int output = result;

    file_to_output << '\t' << _now << ' ' << _now_time << ' '<< " - " << output << '\n';

    file_to_output.close();

}
void output_resuilt_to_console(const Roman_int &result) {

    Roman_int output = result;

    cout
        << print_result
        << output
        << '\n';

}

bool output_is_to_file(Settings &Main_settings) {

    if( Main_settings.get_mode_input() == Modes_input::file ||
        Main_settings.get_mode_output() == Modes_output::to_file ||
        Main_settings.get_mode_output() == Modes_output::to_console_and_file 
    )
        return true;

    return false;
    
}
bool output_is_to_console(Settings &Main_settings) {
    
    if( Main_settings.get_mode_input() == Modes_input::console && (
            Main_settings.get_mode_output() == Modes_output::to_console ||
            Main_settings.get_mode_output() == Modes_output::to_console_and_file ) ||  (
        Main_settings.get_mode_output_with_file() == Modes_output_with_file::on_to_console_and_file )
    ) 
        return true;

    return false;
    
}
