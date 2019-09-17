#include <istream>
#include <string>
#include "Input.h"


Input::Input(std::istream& is) : in(is) {}


int Input::getInt() {
    return -1;
}


std::string Input::getString() {
    return "";
}

