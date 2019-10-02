#include <vector>
#include <string>
#include "OldMaidPlayer.h"
#include "OldMaidTurnView.h"
#include "Deck.h"
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
    determineResult(taken);

    if (player->getHand()->size() == 0)
        return true;
    
    return false;
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
   /* bool pairs = false;
    CardCollection* newCards = new CardCollection();
    int lastValue = -1;

    for (int i = 0; i < cards->size(); i++) {
        int value = cards->getCard(i)->getValue();
        if (value != lastValue) {
            Card const* card = cards->getCard(i);
            newCards->addCard(new Card(card->getValue(), card->getSuit()));
        } else {
            pairs = true;
        }
        lastValue = value;
    }

    if (pairs)
        player->setHand(newCards);
    else
        delete newCards;
        */
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

void OldMaidPlayer::determineResult(Card const* taken) {
    player->getHand()->addCard(taken);
    player->sortHand(true, false);

    int numCards = player->getHand()->size();
    removePairs(player->getHand());

    if (numCards > player->getHand()->size()) {
        view->turnResult(taken, true);
    } else {
        view->turnResult(taken, false);
    }
}
