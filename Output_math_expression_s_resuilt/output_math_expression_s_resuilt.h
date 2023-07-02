
void out_math_expression_result(Settings & Main_Settings, const double &result);
void out_math_expression_result(Settings & Main_Settings, const Roman_int &result);

void output_result_to_file(ofstream &file_to_output, const double &result);
void output_result_to_file(ofstream &file_to_output, const Roman_int &result);
void output_resuilt_to_console(const double &result);
void output_resuilt_to_console(const Roman_int &result);

bool output_is_to_file(Settings &Main_settings);
bool output_is_to_console(Settings &Main_settings);
ofstream open_file_for_output(const string name);
