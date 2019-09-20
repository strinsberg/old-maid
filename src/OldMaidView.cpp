#include <iostream>
#include <ostream>
#include <vector>
#include "OldMaidView.h"
#include "Player.h"
#include "Card.h"


OldMaidView::OldMaidView(
    std::vector<Player*>* p, std::ostream& os)
    : players(p) , out(os) {}


void OldMaidView::turnInfo(int currentPlayer) const {
    Player* player = players->at(currentPlayer);

    out << "=== " << player->getName() << "'s Turn ===" << std::endl;
    out << std::endl;

    out << "-- Hand Sizes --" << std::endl;
    for (auto p : *players)
        out << p->getName() << ": " << p->getHand()->size() << std::endl;

    out << std::endl;
    out << "-- Your Cards --" << std::endl;
    for (int i = 0; i < player->getHand()->size(); i++) {
        Card const* c = player->getHand()->getCard(i);
        out << c->toString() << " ";
    }
    out << std::endl;
    out << std::endl;
}


void OldMaidView::pickCard() const {
    out << "Choose card: ";
}


void OldMaidView::result(
        Card const* card, bool matched, Card const* other) const {
}


void OldMaidView::endRound(int loser) const {
    out << "=== Round Over ===" << std::endl << std::endl;
    out << "Old Maid: ";
    out << players->at(loser)->getName() << std::endl;
}
