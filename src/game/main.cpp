#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Deck.h"
#include "Player.h"
#include "Input.h"
#include "OldMaidView.h"
#include "Deck.h"
#include "OldMaidTurnView.h"
#include "PlayerController.h"
#include "OldMaidRound.h"
#include "OldMaidPlayer.h"


int main() {
    // create objects
    OldMaidView view;
    Input input;
    Deck deck;
    std::vector<PlayerController*> pcs;
    OldMaidRound round(&pcs, &deck, &view);

    // display welcome and collect name information
    view.welcome();
    view.getName();
    std::string name = input.getString();

    // setup round and play
    if (round.makePlayers(name)) {
        round.setup();
        round.play();
    } else {
        std::cout << std::endl;
        std::cout << "Sorry that is not a valid response!!!" << std::endl;
        std::cout << "** Quitting **" << std::endl;
    }

    // clean up
    for (auto p : pcs) {
        delete p;
    }

	return 0;
}
