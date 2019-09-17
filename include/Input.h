#ifndef INPUT_H
#define INPUT_H


#include <iostream>
#include <istream>
#include <string>
#include "View.h"


class Input {
 public:
    /**
     * Creates an object that can be used to get single string tokens of input.
     */
    Input(View* view, std::istream& in = std::cin);

    /**
     * Display the prompt and get a single token of input from the user.
     * @param prompt The text to display before getting input.
     * @return a single string token of input.
     */
    std::string getInput(const std::string& prompt);

 private:
    View* view;  // does not own this
    std::istream& in;
};

#endif
