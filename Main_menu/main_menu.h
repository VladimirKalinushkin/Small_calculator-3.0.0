
#include "enable_mode.cpp"


void welcome_words();

void main_menu(Settings &Main_settings,  TokenStream &Stream);
void enable_Main_modes(Settings &Main_settings, TokenStream &Stream);

void out_promt(Settings &Main_settings);
bool check_exit_simbol(TokenStream &Stream);
void errors_handler(MainException &ex, TokenStream & Stream);

void set_filestream_to_input(Settings &Main_settings);

void check_correct_end_input(TokenStream &Stream);

