
#include "expression_handler_for_Roman_int.h"

void expression_handler_for_Roman_int(TokenStream &Stream)
{

    try
    {
        Roman_int result = third_order_for_Roman_int(Stream);
        cout
            << print_result
            << result
            << '\n';

    }
    catch(Roman_int::exeption ex)
    {
        ex.what();
    }

}
