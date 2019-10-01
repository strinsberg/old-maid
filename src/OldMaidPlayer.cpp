#include <vector>
#include "OldMaidPlayer.h"
#include "OldMaidTurnView.h"
#include "Deck.h"
#include "Player.h"
#include "Input.h"


OldMaidPlayer::OldMaidPlayer(Player* p, OldMaidTurnView* v)
    : player(p), view(v), input(new Input()) {}


bool OldMaidPlayer::takeTurn(Deck* deck, std::vector<Player*> players) {
    /*
    view->turnInfo(players);
    view->playerInfo(player);
    view->takeAction();
    
    // Get a choice from the player
    // Needs input validation for choosing out of range
    // and also for entering quit/help or nonsense.
    std::string in = input->getString();
    int pos = std::stoi(in);

    // get the card from the player to your left
    int left;
    for (int i = 0; i < players.size(); ++i) {
        if (player == players[i]) {
            left = i == 0 ? players.size() - 1 : i - 1;
            break;
        }
    }

    Card* taken = players[left]->takeCard(idx);

    // add the card to the players hand and remove pairs
    player->getHand()->addCard(taken);
    int numCards = player->getHand()->size();
    removePairs(player->getHand());

    // display the result. If the players hand size has decresed the
    // card they picked up gave them a pair.
    if (numCards > player->getHand()->getSize()) {
        view->result(card, true);
    } else {
        view->result(card, false);
    }*/
}

Player* OldMaidPlayer::getPlayer() {
    return player;
}

bool OldMaidPlayer::isOut() {
    return player->getHand()->size() == 0;
}
