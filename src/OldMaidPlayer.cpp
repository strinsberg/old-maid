#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include "OldMaidPlayer.h"
#include "OldMaidTurnView.h"
#include "Deck.h"
#include "Card.h"
#include "CardCollection.h"
#include "Player.h"
#include "Input.h"


OldMaidPlayer::OldMaidPlayer(Player* p, OldMaidTurnView* v, Input* in)
    : player(p), view(v), input(in) {}

OldMaidPlayer::~OldMaidPlayer() {
    delete view;
    delete player;
}


bool OldMaidPlayer::takeTurn(Deck* deck, std::vector<Player*> players) {
    // get player positions
    Player* left = getLeftPlayer(players);

    view->turnInfo();
    view->takeAction(left);

    Card const* taken = getCard(left);
    Card card(taken->getValue(), taken->getSuit());

    // add the card to the players hand and remove pairs
    player->getHand()->addCard(taken);
    int numCards = player->getHand()->size();
    updateHand();

    // determine if a match was made
    if (numCards > player->getHand()->size()) {
        view->turnResult(&card, true);
    } else {
        view->turnResult(&card, false);
    }

    // Wait so player can see their turn info before moving on
    view->wait();
    input->wait();

    // return whether the player is out of the round or not
    if (player->getHand()->size() == 0)
        return true;

    return false;
}

void OldMaidPlayer::updateHand() {
    player->sortHand(true, false);
    removePairs(player->getHand());
}


Player* OldMaidPlayer::getPlayer() {
    return player;
}


bool OldMaidPlayer::isOut() {
    return player->getHand()->size() == 0;
}


// Private/Protected //////////////////////////////////////////////////

// precondition -> the cards must be sorted by value so that
// pairs are next to eachother.
void OldMaidPlayer::removePairs(CardCollection* cards) {
    std::vector<int> pairIdxs;

    // finds the indicies of matched cards
    for (int i = 0; i < cards->size() - 1; i++) {
        Card const* c1 = cards->getCard(i);
        Card const* c2 = cards->getCard(i + 1);

        if (c1->getValue() == c2->getValue()) {
            pairIdxs.push_back(i);
            pairIdxs.push_back(i + 1);
            i++;
        }
    }
    // Tell the card collection to remove all matched cards
    std::vector<Card const*> taken = cards->takeAllCards(pairIdxs);

    // Delete the memory for all the removed cards
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


Card const* OldMaidPlayer::getCard(Player* left) {
    for (int i = 0; i < 10; i++) {
        // Try to get a number from the player
        // If it is out of bounds or not a number ask again
        // If they get it wrong 10 times just take the first card
        try {
            std::string in = input->getString();
            int pos = std::stoi(in);
            return left->getHand()->takeCard(pos - 1);
        } catch (const std::invalid_argument& e) {
            view->badInput("Please enter a number");
        } catch (const std::out_of_range& e) {
            std::string error = "Choose a number between 1 and ";
            error += std::to_string(left->getHand()->size());
            view->badInput(error);
        }
        view->takeAction(left);
    }
    return left->getHand()->takeCard(0);
}

