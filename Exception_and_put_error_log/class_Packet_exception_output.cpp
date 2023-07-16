
#pragma once
#include "class_Packet_exception_output.h"

Packet_exception_output::Packet_exception_output(const char *message) {
    _message = message;
}

Packet_exception_output::Packet_exception_output(const Token &value, const char *message) {
    _value = value;
    _message = message;
}
