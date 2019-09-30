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

#include <iostream>

int OldMaidRound::play() {
    std::vector<bool> inGame(players->size(), true);
    bool run = true;

    while (run) {
        for (int i = 0; i < players->size(); i++) {
            if (!inGame[i])
                continue;

            bool out = (*players)[i]->takeTurn(deck, getPlayers(true));
            if (out) {
                inGame[i] = false;
            }

            int status = gameStatus(inGame);
            if (status != -1) {
                view->endRound(getPlayers(), status);
                run = false;
                break;
            }
        }
    }
}


// Private helpers ////////////////////////////////////////////////////

std::vector<Player*> OldMaidRound::getPlayers(bool onlyPlaying) {
    std::vector<Player*> ps;

    for (int i = 0; i < players->size(); i++) {
        Player* player = (*players)[i]->getPlayer();

        if (onlyPlaying && player->getHand()->size() == 0) {
            ps.push_back(player);
        } else {
            ps.push_back(player);
        }
    }

    return ps;
}


int OldMaidRound::gameStatus(std::vector<bool> inGame) {
    int count = 0;
    int last = 0;

    for (int i = 0; i < inGame.size(); i++) {
        if (inGame[i]) {
            count++;
            last = i;
        }
    }

    if (count == 1) {
        return last;
    }
    return -1;
}
