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


std::string aiNames[] = {"Bill", "Jane", "Wendy", "Max", "Shane", "Alex"};


int main() {
    // create objects
    OldMaidView* view = new OldMaidView();
    Input* input = new Input();
    Deck* deck = new Deck();

    // display welcome and collect name information
    view->welcome();
    view->getName();
    std::string name = input->getString();

    // Create PlayerControllers and a human player
    std::vector<PlayerController*> pcs;

    Player* p = new Player(name);
    OldMaidPlayer* player = new OldMaidPlayer(
        p, new OldMaidTurnView(p), input);
    pcs.push_back(player);

    // Ask for opponent numbers
    view->askNumAI();
    int numOpp;
    
    // make sure a number or valid value is given
    try {
        numOpp = input->getInt();
    } catch (std::invalid_argument& e) {
        numOpp = 0;
    }
    
    if (numOpp < 2 || numOpp > 5) {
        std::cout << std::endl;
        std::cout << "Wrong!!!" << std::endl;
        std::cout << "Game Over" << std::endl;
    } else {
        // Create the players for the given opponents. Didn't make it to create
        // actual AI so they are still human players.
        for (int i = 0; i < numOpp; i++) {
            Player* opp = new Player(aiNames[i]);
            pcs.push_back(
                new OldMaidPlayer(opp, new OldMaidTurnView(opp), input));
        }
        
        // Create round and play
        OldMaidRound *round = new OldMaidRound(&pcs, deck, view);

        round->setup();
        round->play();
        
        delete round;
    }

    // clean up
    delete view;
    delete input;
    delete deck;

    for (auto p : pcs) {
        delete p;
    }

	return 0;
}
