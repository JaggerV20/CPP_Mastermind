#ifndef GUESS_H
#define GUESS_H
#include "Code.hpp"

class Guess{
    public:
        Guess(int color1, int color2, int color3, int color4, Code solution);
        int* getFeedback();
        int* getCode();
};

#endif