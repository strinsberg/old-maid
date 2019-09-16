#ifndef VIEW_H
#define VIEW_H


#include <iostream>
#include <ostream>
#include <string>

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

  protected:
   std::ostream& out;
};

#endif
