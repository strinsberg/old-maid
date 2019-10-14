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
    explicit Input(std::istream& in = std::cin);

    virtual ~Input() {}

    /**
     * Get the first int from a line of input.
     * @return the collected int.
     */
    virtual int getInt();

    /**
     * Get the first string from a line of input.
     * @return a single string token of input.
     */
    virtual std::string getString();

    /**
     * Wait for the user to press enter.
     */
    virtual void wait();

 private:
    std::istream& in;
};

#endif
