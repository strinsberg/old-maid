#include <vector>
#include <stdexcept>
#include <string>
#include "OldMaidRound.h"
#include "PlayerController.h"
#include "OldMaidPlayer.h"
#include "Deck.h"
#include "View.h"
#include "Input.h"


OldMaidRound::OldMaidRound(std::vector<PlayerController*>* ps, Deck* d,
    View* v) : players(ps), deck(d), view(v), input(new Input()) {}


OldMaidRound::~OldMaidRound() {
    delete input;
}


// When testing this class do not run this function if you want to fill
// players with MockOldMaidPlayers.
bool OldMaidRound::makePlayers(std::string name) {
    Player* p = new Player(name);
    players->push_back(new OldMaidPlayer(p, new OldMaidTurnView(p), input));

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
        return false;
    }

    // Create opponents. Originally for AI, but they were never implemented.
    for (int i = 0; i < numOpp; i++) {
        Player* opp = new Player(aiNames[i]);
        players->push_back(
            new OldMaidPlayer(opp, new OldMaidTurnView(opp), input));
    }
    return true;
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


int OldMaidRound::play() {
    std::vector<Player*> stillInGame = getPlayers(true);
    view->beginRound(stillInGame);

    // Loop while more than 1 players are still in the game
    while (stillInGame.size() > 1) {
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
    }  //LCOV_EXCL_LINE
}  //LCOV_EXCL_LINE

void OldMaidRound::setInput(Input* in) {
    delete input;
    input = in;
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

