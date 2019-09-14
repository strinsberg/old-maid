#include <sstream>
#include <string>
#include <stdexcept>
#include "Card.h"

Card::Card(int v, Suit s) : value(v), suit(s) {
    if (v < 1 || v > 13)
        throw std::invalid_argument("Error: value must be in range [1,13]");
}


std::string Card::toString() const {
    std::stringstream ss;

    switch (value) {
        case 1:
            ss << 'A';
            break;
        case 11:
            ss << 'J';
            break;
        case 12:
            ss << 'Q';
            break;
        case 13:
            ss << 'K';
            break;
        default:
            ss << value;
    }

    switch (suit) {
        case Suit::HEART:
            ss << 'H';
            break;
        case Suit::SPADE:
            ss << 'S';
            break;
        case Suit::DIAMOND:
            ss << 'D';
            break;
        case Suit::CLUB:
            ss << 'C';
            break;
    }

    return ss.str();
}
