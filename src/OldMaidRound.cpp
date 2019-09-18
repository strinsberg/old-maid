#include <iostream>
#include <vector>
#include <string>
#include "OldMaidRound.h"
#include "OldMaidView.h"
#include "Round.h"
#include "Deck.h"
#include "Input.h"
#include "Player.h"


bool gameOver(std::vector<Player*>* players) {
    /*int count = 0;
    for (auto p : players) {
        if (p->getHand()->size() > 0)
            count++;
    }*/
    return false;
}


std::string loser(std::vector<Player*>* players) {
    /*for (auto p : players) {
        if (p->getHand()->size() > 0)
            return p->getName();
    }*/
    return "Oops No-one was the old maid!!!";
}


OldMaidRound::OldMaidRound(Deck* deck, std::vector<Player*>* players,
        Input* input, OldMaidView* v)
            : Round(deck, players, input), view(v) {
    deck->shuffle();
    int idx = deck->findCard(12, Suit::CLUB);
    deck->getCard(idx);
}


int OldMaidRound::play() {
    //
}

