#include <iostream>
#include <string>
#include <vector>
#include "OldMaidTurnView.h"
#include "Player.h"
#include "Card.h"


OldMaidTurnView::OldMaidTurnView(Player* p) : player(p) {}


void OldMaidTurnView::turnInfo() {
    std::cout << "==== " << player->getName() << "'s Turn ====";
    std::cout << std::endl << std::endl;
}


// Take a player so that you can see their hand size
void OldMaidTurnView::takeAction() {
    std::cout << "Pick a card position: ";
}


void OldMaidTurnView::badInput(std::string message) {
    std::cout << "Bad input: " << message << std::endl;
}


void OldMaidTurnView::turnResult(Card const* card, bool success) {
    std::cout << "The " << card->toString();
    if (success)
        std::cout << " makes a match!!" << std::endl;
    else
        std:: cout << " is not a match" << std::endl << std::endl;
}

