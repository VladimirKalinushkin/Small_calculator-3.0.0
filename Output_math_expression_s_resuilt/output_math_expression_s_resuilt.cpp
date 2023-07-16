
#pragma once
#include "output_math_expression_s_resuilt.h"


void Mathematic_result::out_math_expression_s_result(Settings & Main_Settings) {

    if(!this->_activate_output)
        return;
        
    if( output_is_to_file(Main_Settings) )
        output_result_to_file(Main_Settings); 

    if(output_is_to_console(Main_settings) || !file_to_output ) 
        output_resuilt_to_console(Main_Settings);
        
}

void Mathematic_result::output_result_to_file(Settings &Main_settings) {

    if(!open_file_to_output(Main_settings.get_name_file_to_output()))
        return;

    Chrono::Date _now;
    Chrono::Time _now_time;

    file_to_output << '\t' << _now << ' ' << _now_time << ' '<< "\t-\t";
    self_output_result(Main_settings, file_to_output);

    file_to_output.close(); 

}
void Mathematic_result::output_resuilt_to_console(Settings &Main_settings) {

    cout << print_result;

    self_output_result(Main_settings, cout);

}

bool Mathematic_result::open_file_to_output(const string  name) {

    file_to_output.open(name, ios::app);
    if(!file_to_output) {
        cerr <<"Невозможно открыть файл для вывода!\n";
        return false;
    }

    return true;

}
void Mathematic_result::self_output_result(Settings &Main_settings, ostream &os) {

    if(Main_settings.get_mode_calculating() == Modes_calculating::arabian)
        os << _double_result << '\n';

    if(Main_settings.get_mode_calculating() == Modes_calculating::roman) 
        os << _roman_int_result << '\n';
    
}

bool output_is_to_file(Settings &Main_settings) {

    return ( 
        Main_settings.get_mode_input() == Modes_input::file ||
        Main_settings.get_mode_output() == Modes_output::to_file ||
        Main_settings.get_mode_output() == Modes_output::to_console_and_file 
    );
}
bool output_is_to_console(Settings &Main_settings) {
    
    return ( 
        Main_settings.get_mode_input() == Modes_input::console && (
            Main_settings.get_mode_output() == Modes_output::to_console ||
            Main_settings.get_mode_output() == Modes_output::to_console_and_file ) ||  
        (
            Main_settings.get_mode_input() == Modes_input::file &&
            Main_settings.get_mode_output_with_file() == Modes_output_with_file::on_to_console_and_file 
        )
    );
}
