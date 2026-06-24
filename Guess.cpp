#include "Guess.hpp"

class Guess{
    //Variables
    int feedbackArray[3];
    //Look into smart pointers
    Code* code;

    Guess(int color1, int color2, int color3, int color4, Code solution){
        *code = Code(color1, color2, color3, color4);
        int* equalsReturn = code->equals(solution);
        for(int i = 0; i < 3; i++){
            feedbackArray[i] = *(equalsReturn + (i * sizeof(int)));
        }
    }

    int* getFeedback(){
        return feedbackArray;
    }

    int* getCode(){
        return code->getCode();
    }
};