#include <istream>
#include <iostream>
#include <string>
#include "Input.h"


Input::Input(std::istream& is) : in(is) {}


int Input::getInt() {
    return std::stoi(getString());
}


std::string Input::getString() {
    std::string str;
    in >> str;
    return str;
}

void Input::wait() {
    in.ignore();
    in.get();
}

