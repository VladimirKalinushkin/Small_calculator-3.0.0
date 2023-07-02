
#pragma once
#include "output_math_expression_s_resuilt.h"


void out_math_expression_s_result(Settings & Main_Settings, const double &result) {

    if( output_is_to_file(Main_Settings) ) {
        ofstream file_to_output = open_file_for_output(Main_Settings.get_name_file_to_output());
        output_result_to_file(file_to_output, result); 
        file_to_output.close();    
    }

    if(output_is_to_console(Main_settings) ) 
        output_resuilt_to_console(result);

}
void out_math_expression_s_result(Settings & Main_Settings, const Roman_int &result) {

    if( output_is_to_file(Main_Settings) ) {
        ofstream file_to_output = open_file_for_output(Main_Settings.get_name_file_to_output());
        output_result_to_file(file_to_output, result); 
        file_to_output.close();    
    }
    
    if(output_is_to_console(Main_settings) ) 
        output_resuilt_to_console(result);

}

void output_result_to_file(ofstream &file_to_output, const double &result) {


    Chrono::Date _now;
    Chrono::Time _now_time;

    file_to_output << '\t' << _now << ' ' << _now_time << ' '<< "\t-\t" << result << '\n';

}
void output_result_to_file(ofstream &file_to_output, const Roman_int &result) {

    Chrono::Date _now;
    Chrono::Time _now_time;
    Roman_int output = result;

    file_to_output << '\t' << _now << ' ' << _now_time << ' '<< " - " << output << '\n';

}

void output_resuilt_to_console(const double &result) {

    cout
        << print_result
        << result
        << '\n';

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
        Main_settings.get_mode_input() == Modes_input::file &&
        Main_settings.get_mode_output_with_file() == Modes_output_with_file::on_to_console_and_file )
    ) 
        return true;

    return false;
    
}

ofstream open_file_for_output(const string name) {

        ofstream file_to_output(name, ios::app);
        if(!file_to_output)
            cerr <<"Невозможно открыть файл для вывода!\n";

        return file_to_output;

}