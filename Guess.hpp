#ifndef GUESS_H
#define GUESS_H
#include "Code.hpp"

class Guess{
    public:
        Guess(Code code);
        int* getFeedback();
        int* getCode();
};

#endif