#include <ostream>
#include <string>
#include "View.h"


View::View(std::ostream& o) : out(o) {}


void View::displayMessage(const std::string& message) {
    out << message;
}
