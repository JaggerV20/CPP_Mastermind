#include "PlayerInterface.hpp"

class PlayerInterface{
    //Variables
    int returnInt;

    //Wrapper function for iostream 
    //Return an integer from user input. 
    //Come back to this for exception handling. This should be fine since there isn't an "exit" value that could be entered
    //for confusing behavior, but it's worth keeping in mind.
    //The only valid numbers will likely be 1-6, but the Game class will handle that.
    int readInteger(){
        std::cin >> returnInt;
        if(std::cin.fail()){
            std::cin.clear();
            return -1;
        }
        return returnInt;
    }
};