#include "Code.hpp"
/*
Class representing a four peg code. Each peg can be one of six colors represented by numbers 0 to 5
*/
class Code {
    //Variables
    int codeSize = 4;//For convenience. I remember C++ is finnicky with variable length arrays
    int codeArray[4];//This could probably be a constant value if a longer code is wanted. That or a some named value

    //Constructor. Takes four colors to add to the codeArray
    Code(int color1, int color2, int color3, int color4){
        codeArray[0] = color1;
        codeArray[1] = color2;
        codeArray[2] = color3;
        codeArray[4] = color4;
    }

    //Return the codeArray
    int* getCode(){
        return codeArray;
    }
    
    //Check if two codes are equal. Return a feedback array indicating how the codes compare
    //Format: [incorrect pegs, correct color in wrong location pegs, completely correct pegs]
    int* equals(Code codeToCompare){
        //Arrays used to determine if a peg has been counted. If 1, it should be skipped in comparisons
        int selfIsCounted[4] = {0, 0, 0, 0};
        int compareIsCounted[4] = {0, 0, 0, 0};
        //Array to return. Default value is all incorrect.
        int feedbackArray[3] = {4, 0, 0};
        //Get the comparison codeArray
        int* compareCodeArray = codeToCompare.getCode();
        //Check what pegs are completely correct
        for(int i = 0; i < codeSize; i++){
            if((codeArray + (i * sizeof(int))) == (compareCodeArray + (i * sizeof(int)))){
                selfIsCounted[i] = 1;
                compareIsCounted[i] = 1;
                feedbackArray[0] = feedbackArray[0] - 1;
                feedbackArray[2] = feedbackArray[2] + 1;
            }
        }
        //Check what pegs have the correct color, but are in the wrong spot
        for(int i = 0; i < codeSize; i++){
            //Only run comparisons if the value hasn't been counted yet
            if(selfIsCounted[i] == 0){
                for(int j = 0; j < codeSize; i++){
                    //If a value in the comparison code hasn't been counted and the colors are equal
                    if((compareIsCounted[i] != 1) && ((codeArray + (i * sizeof(int))) == (compareCodeArray + (j * sizeof(int))))){
                        selfIsCounted[i] = 1;
                        compareIsCounted[j] = 1;
                        feedbackArray[0] = feedbackArray[0] - 1;
                        feedbackArray[1] = feedbackArray[1] + 1;
                        break;//Since the value has been counted, we can move to the next value. Return to the for int i loop
                    }
                }
            }
        }
        return feedbackArray;
    }
};