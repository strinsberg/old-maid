#include <ostream>
#include <vector>
#include "OldMaidView.h"
#include "Player.h"


OldMaidView::OldMaidView(
    std::vector<Player*>* p, std::ostream& os)
    : players(p) , out(os) {}


void OldMaidView::playerInfo(int currentPlayer) const {
}


void OldMaidView::pickCard() const {
}


void OldMaidView::result(Card const* card, bool matched) const {
}


void OldMaidView::endRound(int loser) const {
}
