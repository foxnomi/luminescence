#include "raylib.h"
#include <string>
#include <iostream>

using namespace std;

// TO DO: Please for the love of fucking god remember to add history to this //
// That and also make sure that when doing responses to the console that it wraps back around properly

class debugConsole {
    public:
        // Define vars first, then methods
        bool consoleOpen = false;
        string currentLine;
        int backspaceCooldown = 4;
        int maxChars = 255;


        // Methods go here
        void tick() { // Ran every frame
            // Runs in order
            openConsole();
            consoleTyping();
        }

        void openConsole() { // Checks if already open or not, then changes the var accordingly
            if(IsKeyPressed(KEY_F3)) {
                // The check itself
                if(consoleOpen == false) {
                    consoleOpen = true;
                    cout << "Console Opened\n";
                } else {
                    consoleOpen = false;
                    currentLine = "";
                    cout << "Console Closed\n";
                }
            }
        }

        void consoleTyping() { // Does logic in relation to what is currently being typed in chat
            if(consoleOpen) {
                int tempHolder = -1;
                while(tempHolder != 0) {
                    // Temp vars
                    tempHolder = GetCharPressed();
                    if(tempHolder != 0 && currentLine.size() <= maxChars) { // Add the char into the console line
                        currentLine += tempHolder;
                    }
                    if(currentLine.length() > 0) { // Only allow backspaces if the line has characters
                        if(IsKeyPressed(KEY_BACKSPACE)) { // Backspace hold check
                            // First backspace
                            currentLine.pop_back();
                            backspaceCooldown = 12;
                        } else if(IsKeyDown(KEY_BACKSPACE)) {
                            // Held backspaces
                            backspaceCooldown -= 1;
                            if(backspaceCooldown <= 1) {
                                currentLine.pop_back();
                                backspaceCooldown = 4;
                            }
                        }
                    }
                }
            }
        }

        void printConsoleLine() { // Idk how the fuck this works but it did so I'm no longer touching it
            // Temp Vars
            int loop = currentLine.length() + 1;
            char text[loop];
            // Loop over the string
            for(int i = 0; i < loop; i++) {
                text[i] = currentLine[i];
            }
            text[loop] = '\n';
            // Print the text???
            DrawText(text, 0, GetScreenHeight() - 30, 30, WHITE); // So you have to pass an array of said text to get it to work...
            // Please for the love of god make a text handler class or something, it would make it so much easier
        }
};