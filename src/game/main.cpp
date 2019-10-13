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
    
    std::vector<PlayerController*> pcs;
    Player* p = new Player(name);
    OldMaidPlayer* player = new OldMaidPlayer(
        p, new OldMaidTurnView(p), input);
    pcs.push_back(player);

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

	return 0;
}
