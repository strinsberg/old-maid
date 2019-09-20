#include <iostream>
#include <vector>
#include <string>
#include "OldMaidRound.h"
#include "OldMaidView.h"
#include "Round.h"
#include "Deck.h"
#include "Input.h"
#include "Player.h"
#include "Hand.h"


OldMaidRound::OldMaidRound(Deck* deck, std::vector<Player*>* pls,
        Input* input, OldMaidView* v)
            : Round(deck, pls, input), view(v) {
    deck->shuffle();
    int idx = deck->findCard(12, Suit::CLUB);
    Card const* card = deck->takeCard(idx);
    delete card;

    std::vector<Hand*> hands = deck->deal(players->size(), 0);
    for (int i = 0; i < players->size(); i++)
       (*players)[i]->setHand(hands[i]);
}


int OldMaidRound::play() {
    // while the game is still going
        // show turn info
        // ask to pick a card from player
        // show the result
    // show result of round
}

