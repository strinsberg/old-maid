#include <ostream>
#include <vector>
#include "OldMaidView.h"
#include "View.h"


OldMaidView::OldMaidView(std::ostream& out) : View(out) {}


void OldMaidView::displayHand(Hand* hand) {
    out << hand->toString();
}


void OldMaidView::displayPlayers(const std::vector<Player*>& players) {
    for (int i = 0; i < players.size(); i++) {
        out << players[i]->getName() << ":";
        out << players[i]->getHand()->size();

        if (i < players.size() - 1)
            out << ", ";
    }
}
