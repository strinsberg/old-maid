#include <vector>
#include "OldMaidRound.h"
#include "PlayerController.h"
#include "Deck.h"
#include "View.h"
#include "Input.h"


OldMaidRound::OldMaidRound(std::vector<PlayerController*> ps, Deck* d,
    View* v) : players(ps), deck(d), input(new Input()), view(v) {}


OldMaidRound::~OldMaidRound() {
    delete input;
}


void OldMaidRound::setup() {
}


int OldMaidRound::play() {
}
