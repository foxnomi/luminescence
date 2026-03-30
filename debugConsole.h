#include "raylib.h"
#include <string>
#include <iostream>

using namespace std;

// TO DO: Please for the love of fucking god remember to add history to this
// 3/30/26 1:30am Later. Also fuck you for making this I think
// That and also make sure that when doing responses to the console that it wraps back around properly

// Backspace cooldown first = .2 seconds, afterward is reduced to .05

class debugConsole {
    public:
        // Define vars first, then methods
        bool consoleOpen = false;
        char currentLine[];

    void openConsole(){
        // Open the console when F3 is hit, close if opened (May change later)
        if (IsKeyPressed(KEY_F3) && consoleOpen == false) {
            consoleOpen = true;
        } else if (IsKeyPressed(KEY_F3) && consoleOpen == true) {
            consoleOpen = false;
        }
    }

    void consoleTyping(){
        // While the console is open, allow stuff to be typed
        int temp = -1;
        while (temp != 0) {
            return;
        }
    }

};