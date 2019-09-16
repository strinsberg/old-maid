#ifndef VIEW_H
#define VIEW_H


#include <iostream>
#include <ostream>
#include <string>
#include "Hand.h"
#include "Player.h"


/**
 * Base class for displaying game data to screen.
 * @author Steven Deutekom
 * @date sept 15, 2019
 */
class View {
  public:
   /**
    * Creates a new view.
    */
   View(std::ostream& out=std::cout);

   /**
    * Display the given message to the screen.
    *
    * Does not add a newline.
    *
    * @param message The string to display.
    */
   void displayMessage(const std::string& message);
   
   /**
    * Displays the contents of a players hand.
    * @param hand The hand to display.
    */
   virtual void displayHand(Hand* hand)=0;

   /**
    * Displays info about the players.
    * The main purpose is to show how many cards each player has left.
    * @param players The players to show information for.
    */
   virtual void displayPlayers(std::vector<Player*>& players)=0;

  protected:
   std::ostream& out;
};

#endif
