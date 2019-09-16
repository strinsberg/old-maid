#include <iostream>
#include <vector>
#include "Deck.h"
#include "Player.h"
#include "OldMaidRound.h"
#include "View.h"
#include "OldMaidView.h"
#include "Input.h"


int main() {
	std::vector<Player*> players;
	players.push_back(new Player("Steve"));
	players.push_back(new Player("Other"));
	
	Deck* d = new Deck();
	OldMaidView* v = new OldMaidView();
	Input* in = new Input(v);
	
	OldMaidRound round(d, v, in);
	
	std::cout << "==== Old Maid Demo ====" << std::endl << std::endl;
	
	
	round.play(players);
	
	std::cout << "==== End ====" << std::endl;
	
	for (auto p : players)
	    delete p;
	
	return 0;
}
