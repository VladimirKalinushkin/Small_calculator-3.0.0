
#include "help.cpp"
#include "welcome_words.cpp"

void main_menu(Settings &Main_settings,  TokenStream &Stream);

void out_promt(Settings &Main_settings);

bool check_exit_simbol(TokenStream &Stream);
bool enable_Main_modes(Settings &Main_settings, TokenStream &Stream);

void set_filestream_to_input(Settings &Main_settings);
void check_correct_end_input(TokenStream &Stream);

void errors_handler(MainException &ex, Settings &Main_settings);

