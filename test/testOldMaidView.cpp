#include <gtest/gtest.h>
#include <sstream>
#include "OldMaidView.h"
#include "Player.h"
#include "Hand.h"
#include "Card.h"


TEST(TestOldMaidView, new_view) {
   std::stringstream ss;
   OldMaidView v(ss);

   v.displayMessage("testing ...");
   
   EXPECT_EQ(ss.str(), "testing ...");
}


TEST(TestOldMaidView, display_hand) {
   std::stringstream ss;
   OldMaidView v(ss);
   Hand h;
   Card const* c1 = new Card(1, Suit::HEART);
   Card const* c2 = new Card(2, Suit::SPADE);
   Card const* c3 = new Card(10, Suit::CLUB);
   Card const* c4 = new Card(13, Suit::DIAMOND);
   
   h.addCard(c1);
   h.addCard(c2);
   h.addCard(c3);
   h.addCard(c4);
   v.displayHand(&h);

   EXPECT_EQ(ss.str(), "AH, 2S, 10C, KD");
};


TEST(TestOLDMaidView, display_players) {
   std::stringstream ss;
   OldMaidView v(ss);
   
   Player* p1 = new Player("P1");
   Player* p2 = new Player("P2");
   std::vector<Player*> players = {p1, p2};
   Hand* h1 = new Hand();
   Hand* h2 = new Hand();

   Card const* c1 = new Card(1, Suit::HEART);
   Card const* c2 = new Card(2, Suit::SPADE);
   Card const* c3 = new Card(10, Suit::CLUB); 

   h1->addCard(c1);
   h2->addCard(c2);
   h2->addCard(c3);
   v.displayPlayers(players);

   EXPECT_EQ(ss.str(), "P1:1, P2:2"); 

   delete p1, p2;
}
