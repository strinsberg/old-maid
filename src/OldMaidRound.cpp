#include <iostream>
#include <vector>
#include <string>
#include "OldMaidRound.h"
#include "OldMaidView.h"
#include "Round.h"
#include "Deck.h"
#include "Input.h"
#include "Player.h"


OldMaidRound::OldMaidRound(Deck* deck, std::vector<Player*>* players,
        Input* input, OldMaidView* v)
            : Round(deck, players, input), view(v) {
    deck->shuffle();
    int idx = deck->findCard(12, Suit::CLUB);
    Card const* card = deck->takeCard(idx);
    delete card;
}


int OldMaidRound::play() {
    // deal cards
    // while the game is still going
        // show turn info
        // ask to pick a card from player
        // show the result
    // show result of round
}

