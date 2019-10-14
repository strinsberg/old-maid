#include <iostream>
#include <vector>
#include <string>
#include "Deck.h"
#include "Player.h"
#include "Input.h"
#include "OldMaidView.h"
#include "Deck.h"
#include "OldMaidTurnView.h"
#include "PlayerController.h"
#include "OldMaidRound.h"
#include "OldMaidPlayer.h"


std::string aiNames[] = {"Bill", "Jane", "Wnedy", "Max", "Shane", "Alex"};


int main() {
    // create objects
    OldMaidView* view = new OldMaidView();
    Input* input = new Input();
    Deck* deck = new Deck(); 
    

    // display and collect information
    view->welcome();

    view->getName();
    std::string name = input->getString();

    // Create PlayerControllers and a user player
    std::vector<PlayerController*> pcs;

    Player* p = new Player(name);
    OldMaidPlayer* player = new OldMaidPlayer(
        p, new OldMaidTurnView(p), input);
    pcs.push_back(player);

    // Create other players
    // currently there are not AI players so just creates more regular players
    view->askNumAI();
    int numOpp = input->getInt();
    
    for (int i = 0; i < numOpp; i++) {
        Player* opp = new Player(aiNames[i]);
        pcs.push_back(
            new OldMaidPlayer(opp, new OldMaidTurnView(opp), input));
    }
    
    OldMaidRound* round = new OldMaidRound(&pcs, deck, view);
    
    // start round
    round->setup();
    round->play();

    // clean up
    delete round;
    delete view;
    delete input;
    delete deck;

    for (auto p : pcs) {
        delete p;
    }

	return 0;
}
