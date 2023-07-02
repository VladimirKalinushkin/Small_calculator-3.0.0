
class MainException : public exception
{

public:
    MainException() {}
    MainException(const char *message);
    MainException(const Token &value, const char *message);

    void what();
    void put_to_file(ofstream &file_to_output_log);

private:
    Packet_exception_output _value;
};

ostream &operator<<(ostream &os, Token t);
ostream &operator<<(ostream &os, Packet_exception_output p);
