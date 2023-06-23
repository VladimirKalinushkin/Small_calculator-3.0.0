
#pragma once
#include "class_MainException.h"

MainException::MainException(const char *message)
{
    _value = Packet_exception_output(message);
}
MainException::MainException(const Token &value, const char *message)
{
    _value = Packet_exception_output(value, message);
}

void MainException::what()
{
    cerr << this->_value._message
         << '\n';
            

    if(_value._value.type)
        cerr    << "( "
                << "Передано: "
                << _value._value.type
                << ' '
                << _value._value.value
                << ' '
                << _value._value.word
                << " )"
                << '\n';

}

void MainException::put_to_file(ofstream &os, const string &name)
{

    os.open(name, ios::app);

    if (os.is_open())
        os << _value;
    else
        cerr << "Не удалось открыть файл вывода! \n";

    os.close();
}

ostream &operator<<(ostream &os, Token t)
{

    if (t.type)
        os << "\t"
           << "type:"
           << "\t"
           << t.type
           << "\n"
           << "\t"
           << "value:"
           << "\t"
           << t.value
           << "\n"
           << "\t"
           << "word:"
           << "\t"
           << t.word
           << '\n';

    else
        os << "{ -- No Token -- }\n";

    return os;
}

ostream &operator<<(ostream &os, Packet_exception_output p)
{

    os << '\n'
       << "</ "
       << p._now
       << " "
       << p._this_time
       << '\n';

    os << "value:"
       << '\n'
       << p._value;

    os << "message:"
       << '\n';

    if (p._message)
        os << "\t\""
           << p._message
           << "\""
           << '\n';
    else
        os << "\t\""
           << "Сообщения не передано!"
           << "\""
           << '\n';

    os << ">"
       << '\n';

    return os;
}
