#include <iostream>
#include <vector>
#include <string>
#include "OldMaidRound.h"
#include "OldMaidView.h"
#include "Round.h"
#include "Deck.h"
#include "Input.h"
#include "Player.h"
#include "Hand.h"


OldMaidRound::OldMaidRound(Deck* d, std::vector<Player*>* pls,
        Input* in, OldMaidView* v)
            : Round(d, pls, in), view(v) {
    deck->shuffle();
    int idx = deck->findCard(12, Suit::CLUB);
    Card const* card = deck->takeCard(idx);
    delete card;

    std::vector<Hand*> hands = deck->deal(players->size(), 0);
    for (int i = 0; i < players->size(); i++)
       (*players)[i]->setHand(hands[i]);
}


int OldMaidRound::play() {
    while (!roundOver()) {
        for (int i = 0; i < players->size(); i++) {
            if ((*players)[i]->getHand()->size() == 0)
                continue;

            view->turnInfo(i);
            view->pickCard();

            int choice = input->getInt();
            int to_left = i == players->size() - 1 ? 0 : i + 1;
            Card const* pick = (*players)[to_left]->getHand()->takeCard(choice);

            int idx = (*players)[i]->getHand()->matchCard(pick->getValue());
            if (idx != -1) {
               Card const* card = (*players)[i]->getHand()->takeCard(idx);
               view->result(pick, true, card);
               delete card;
               delete pick;
            } else {
               view->result(pick, false);
               (*players)[i]->getHand()->addCard(pick);
            }
        }
    }
    view->endRound(getLoser());
}


bool OldMaidRound::roundOver() const {
    int count = 0;
    for (auto p : *players) {
        if (p->getHand()->size() > 0)
            count++;
    }
    return count <= 1;
}


int OldMaidRound::getLoser() const {
    for (int i = 0; i < players->size(); i++) {
        if ((*players)[i]->getHand()->size() > 0)
            return i;
    }
}
