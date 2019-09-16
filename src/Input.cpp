#include <istream>
#include <string>
#include "Input.h"
#include "View.h"


Input::Input(View* v, std::istream& is) : view(v), in(is) {}


std::string Input::getInput(const std::string& prompt) {
   std::string input;
   view->displayMessage(prompt);
   in >> input;
   return input;
}  
