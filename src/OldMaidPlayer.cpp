#include <vector>
#include <string>
#include <iostream>
#include "OldMaidPlayer.h"
#include "OldMaidTurnView.h"
#include "Deck.h"
#include "Card.h"
#include "CardCollection.h"
#include "Player.h"
#include "Input.h"


OldMaidPlayer::OldMaidPlayer(Player* p, OldMaidTurnView* v, Input* in)
    : player(p), view(v), input(in) {}


bool OldMaidPlayer::takeTurn(Deck* deck, std::vector<Player*> players) {
    // get player positions
    Player* left = getLeftPlayer(players);

    view->turnInfo();
    view->takeAction();

    Card const* taken = getCard(left);

    // add the card to the players hand and remove pairs
    player->getHand()->addCard(taken);
    int numCards = player->getHand()->size();
    updateHand();

    if (numCards > player->getHand()->size()) {
        view->turnResult(taken, true);
    } else {
        view->turnResult(taken, false);
    }

    if (player->getHand()->size() == 0)
        return true;

    return false;
}

void OldMaidPlayer::updateHand() {
    // remove cards in this case
    player->sortHand(true, false);
    removePairs(player->getHand());
}


Player* OldMaidPlayer::getPlayer() {
    return player;
}

bool OldMaidPlayer::isOut() {
    return player->getHand()->size() == 0;
}


// precondition -> the cards must be sorted by value so that
// pairs are next to eachother.
void OldMaidPlayer::removePairs(CardCollection* cards) {
    std::vector<int> pairIdxs;

    for (int i = 0; i < cards->size() - 1; i++) {
        Card const* c1 = cards->getCard(i);
        Card const* c2 = cards->getCard(i + 1);

        if (c1->getValue() == c2->getValue()) {
            pairIdxs.push_back(i);
            pairIdxs.push_back(i + 1);
            i++;
        }
    }
    std::vector<Card const*> taken = cards->takeAllCards(pairIdxs);

    for (auto c : taken)
        delete c;
}

Player*  OldMaidPlayer::getLeftPlayer(const std::vector<Player*>& players) {
    int left;

    for (int i = 0; i < players.size(); ++i) {
        if (player == players[i]) {
            left = i == 0 ? players.size() - 1 : i - 1;
            break;
        }
    }

    return players[left];
}

// redefine for AI to give input
// needs some kind of input validation and command handling
Card const* OldMaidPlayer::getCard(Player* left) {
    std::string in = input->getString();
    int pos = std::stoi(in);

    return left->getHand()->takeCard(pos);
}

