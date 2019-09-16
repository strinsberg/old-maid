#include <ostream>
#include <vector>
#include "OldMaidView.h"
#include "View.h"


OldMaidView::OldMaidView(std::ostream& out) : View(out) {}


void OldMaidView::displayHand(Hand* hand) {
   out << "hand";
}


void OldMaidView::displayPlayers(std::vector<Player*>& players) {
   out << "players";
}
