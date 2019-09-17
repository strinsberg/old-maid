#ifndef INPUT_H
#define INPUT_H


#include <iostream>
#include <istream>
#include <string>


/**
 * Gets input from the user.
 * @author Steven Deutekom
 * @date sept 17, 2019
 */
class Input {
 public:
    /**
     * Creates an object that can be used to get single string tokens of input.
     */
    Input(std::istream& in = std::cin);

    /**
     * Get the first int from a line of input.
     * @return the collected int.
     */
    int getInt();
    
    /**
     * Get the first string from a line of input.
     * @return a single string token of input.
     */
    std::string getString();

 private:
    std::istream& in;
};

#endif
