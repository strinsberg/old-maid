#include <istream>
#include <string>
#include "Input.h"


Input::Input(std::istream& is) : in(is) {}


int Input::getInt() {
    int temp;
    in >> temp;
    return temp;
}


std::string Input::getString() {
    std::string str;
    in >> str;
    return str;
}

