#include <vector>
#include "OldMaidRound.h"
#include "PlayerController.h"
#include "Deck.h"
#include "View.h"
#include "Input.h"


OldMaidRound::OldMaidRound(std::vector<PlayerController*>* ps, Deck* d,
    View* v) : players(ps), deck(d), input(new Input()), view(v) {}


OldMaidRound::~OldMaidRound() {
    delete input;
}


void OldMaidRound::setup() {
    // Remove 3 queens from the deck
    CardCollection* cards = deck->getCards();
    for (int i = 0; i < 3; i++) {
        int pos = cards->findCard(12, static_cast<Suit>(i + 1));
        Card const* queen = cards->takeCard(pos);
        delete queen;
    }

    // Shuffle and deal out hands to each player
    deck->shuffle();
    std::vector<CardCollection*> hands = deck->deal(players->size(), 0);
    for (int i = 0; i < players->size(); ++i) {
        (*players)[i]->getPlayer()->setHand(hands[i]);
    }
}


int OldMaidRound::play() {
    // for each player
    // play the players turn
    // if the player is out decrement count or something
    // display round over when finished
    /*std::vector<bool> inGame(players.size(), true);

    for (int i = 0; i < players->size(); i++) {
        bool out = (*players)[i]->takeTurn(deck, getPlayers(players));
        if (out) {
            psInGame[i] = false;
        }

        std::pair<bool, int> status = gameStatus(inGame);
        if (!status.first) {
            view->endRound(getPlayers(players, true), status.second);
        }
    }*/
}
