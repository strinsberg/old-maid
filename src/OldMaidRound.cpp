#include <vector>
#include <string>
#include "OldMaidRound.h"
#include "Round.h"
#include "Deck.h"
#include "View.h"
#include "Input.h"
#include "Player.h"


bool gameOver(std::vector<Player*>& players) {
    int count = 0;
    for (auto p : players) {
        if (p->getHand()->size() > 0)
            count++;
    }
    return count < 2;
}


std::string loser(std::vector<Player*>& players) {
    for (auto p : players) {
        if (p->getHand()->size() > 0)
            return p->getName();
    }
    return "Oops No-one was the old maid!!!";
}


OldMaidRound::OldMaidRound(Deck* deck, View* view, Input* input)
        : Round(deck, view, input) {}


void OldMaidRound::play(std::vector<Player*>& players) {
    // take out a queen
    // shuffle the deck
    deck->shuffle();
    
    // deal hands
    int num_players = players.size();
    std::vector<Hand*> hands = deck->deal(num_players);
    for (int i = 0; i < num_players; i++)
        players[i]->setHand(hands[i]);
    
    // while there are at least 2 players with cards left
    while(!gameOver(players)) {
        for (int i = 0; i < players.size(); i++) {
            // See if the player is still in the game
            if (players[i]->getHand()->size() == 0)
                continue;
                
            // display whose turn it is
            view->displayMessage(
                "\n=== Player " + players[i]->getName() + "'s Turn ===\n\n");
            
            // Display players statuses
            view->displayMessage("Game Status: ");
            view->displayPlayers(players);
            view->displayMessage("\n\n");
            
            // Ask for a card
            std::string in = input->getInput("Choose a card> ");
            int pick = std::stoi(in);
            
            // Take the card from the opponent
            int p_idx = i == players.size() - 1 ? 0 : i - 1;
            Card const* card = players[p_idx]->getHand()->takeCard(pick);
            
            // If the card is a match for one in the players hand
            // remove the matched card and delete them from the game.
            // Else add the card to the players hand.
            int match = players[i]->getHand()->matchCard(card->getValue());
            if (match != -1) {
                view->displayMessage("\nThat gives you a match\n");
                Card const* matched_card = players[i]->getHand()->takeCard(match);
                delete card;
                delete matched_card;
            } else {
                view->displayMessage("\nThe card does not give you a match\n");
                players[i]->getHand()->addCard(card);
            }
        }
    }
    // display the player who is the old maid
    view->displayMessage("\n*** Round Over ***\n");
    view->displayMessage(loser(players) + "\n");
}

