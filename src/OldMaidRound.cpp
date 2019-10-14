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
        (*players)[i]->updateHand();
    }
}

#include <iostream>

int OldMaidRound::play() {
    std::vector<Player*> stillInGame = getPlayers(true);
    view->beginRound(stillInGame);

    while (stillInGame.size() > 0) {
        for (int i = 0; i < players->size(); i++) {
            if ((*players)[i]->isOut()) {
                continue;
            }

            // take the players turn with the remaining players
            stillInGame = getPlayers(true);
            if (stillInGame.size() <= 1) {
                view->endRound(getPlayers(), i);
                return i;
            }

            view->gameStatus(stillInGame);
            (*players)[i]->takeTurn(deck, stillInGame);
        }
    }
}


// Private helpers ////////////////////////////////////////////////////

std::vector<Player*> OldMaidRound::getPlayers(bool onlyPlaying) {
    std::vector<Player*> ps;

    for (int i = 0; i < players->size(); i++) {
        if (onlyPlaying && (*players)[i]->isOut()) {
                continue;
        }

        ps.push_back((*players)[i]->getPlayer());
    }

    return ps;
}

