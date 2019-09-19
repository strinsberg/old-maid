#include <ostream>
#include <vector>
#include "OldMaidView.h"
#include "Player.h"


OldMaidView::OldMaidView(
    std::vector<Player*>* p, std::ostream& os)
    : players(p) , out(os) {}


void OldMaidView::turnInfo(int currentPlayer) const {
}


void OldMaidView::pickCard() const {
    out << "Choose card: ";
}


void OldMaidView::result(Card const* card, bool matched) const {
}


void OldMaidView::endRound(int loser) const {
}
