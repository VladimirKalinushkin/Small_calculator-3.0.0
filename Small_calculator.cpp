
#include "Small_calculator.h"



int main() {

    welcome_words();

    try {

        main_menu(Main_settings, Stream);

    }
    catch(const char* err){

        cerr << err << "Произошла неизвестная ошибка!";
        system("pause");

    }
     
    return 0;
	
}
