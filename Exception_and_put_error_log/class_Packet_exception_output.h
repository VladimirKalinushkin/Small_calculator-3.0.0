
class Packet_exception_output
{

public:
    Chrono::Date _now;
    Chrono::Time _this_time;
    Token _value;
    const char *_message = NULL;

    Packet_exception_output() {}
    Packet_exception_output(const char *message);
    Packet_exception_output(const Token &value, const char *message);
};
