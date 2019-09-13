#ifndef CARD_H
#define CARD_H


#include "Suit.h"

class Card {
  public:
   Card(int v, Suit s) : value(v), suit(s) {};
   int getValue() const {return value;}
   int getSuit() const {return suit;}

  private:
   int value;
   Suit suit;
};

#endif
