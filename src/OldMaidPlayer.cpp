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
    int left, playerI;
    for (int i = 0; i < players.size(); ++i) {
        if (player == players[i]) {
            left = i == 0 ? players.size() - 1 : i - 1;
            playerI = i;
            break;
        }
    }

    view->turnInfo();
    view->takeAction();

    // Get a choice from the player
    // Needs input validation for choosing out of range
    // and also for entering quit/help or nonsense.
    std::string in = input->getString();
    int pos = std::stoi(in);

    Card const* taken = players[left]->getHand()->takeCard(pos);

    // add the card to the players hand and remove pairs
    player->getHand()->addCard(taken);
    int numCards = player->getHand()->size();
    removePairs(player->getHand());

    // display the result. If the players hand size has decresed the
    // card they picked up gave them a pair.
    if (numCards > player->getHand()->size()) {
        view->turnResult(taken, true);
    } else {
        view->turnResult(taken, false);
    }
    
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


void OldMaidPlayer::removePairs(CardCollection* cards) {
}
