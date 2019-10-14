#include <iostream>
#include <string>
#include <vector>
#include "OldMaidTurnView.h"
#include "Player.h"
#include "Card.h"


OldMaidTurnView::OldMaidTurnView(Player* p) : player(p) {}


void OldMaidTurnView::turnInfo() {
    std::cout << "---- " << player->getName() << "'s Turn ----" << std::endl;
    std::cout << "Hand: " << player->getHand()->toString();
    std::cout << std::endl << std::endl;
}


// Take a player so that you can see their hand size
void OldMaidTurnView::takeAction(Player* opponent) {
    std::cout << "Pick a card from " << opponent->getName() << std::endl;
    std::cout << "Enter number between 1 and ";
    std::cout << opponent->getHand()->size() << ": ";
}


void OldMaidTurnView::badInput(std::string message) {
    std::cout << std::endl << "*** Bad input: " << message << " ***";
    std::cout << std::endl << std::endl;
}


void OldMaidTurnView::turnResult(Card const* card, bool success) {
    std::cout << std::endl;
    std::cout << "You picked the ** " << card->toString() << " **" << std::endl;
    if (success)
        std::cout << "That makes pair (^-^)";
    else
        std:: cout << "That does not make a pair (@_@)";

    std::cout << std::endl << std::endl;
}

void OldMaidTurnView::wait() {
    std::cout << "** Press ENTER to continue ... **";
}
