#include <raylib.h>
#include <vector>
#include <iostream>

#include "gameplayObjs.cpp"

using namespace std;

// Alpha 1.1
// 4/1/26

GameplayObjs* debugObjs() {
    if (IsKeyPressed(KEY_F1)) {
        return new Player;
    }
    return NULL;
}

int main() {
    // Setup vars, such as window and fps parameters
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Luminescence Alpha 1.1");
    SetWindowState(FLAG_FULLSCREEN_MODE);
    SetTargetFPS(60);

    // Class vars and important vars
    vector<GameplayObjs*> gameplayObjs; // REMEMBER TO DELETE THE CLASSES!!!

    // The main game loop
    while(!WindowShouldClose()) {
        // Right here is where all the ACTUAL code updating goes

        GameplayObjs* tempObjHolder = debugObjs(); // Adds new GameplayObjs to a list
        if (tempObjHolder != NULL) {
            gameplayObjs.push_back(tempObjHolder);
            cout << tempObjHolder << "\n";
        }

        for (int x = 0; x < gameplayObjs.size(); x++) {
            if(gameplayObjs[x]->objType == "Player") { // If is a player object
                // This shit does NOT work
                gameplayObjs[x]->tick();
            }
        }

        BeginDrawing(); // Start the screen updating
            ClearBackground(BLACK);
            for (int x = 0; x < gameplayObjs.size(); x++) {
            if(gameplayObjs[x]->objType == "Player") { // If is a player object
                // This shit DOES IN FACT WORK!!!!!!
                // HOLY FUCK
                // 4/2/26 12:36am
                gameplayObjs[x]->draw();
            }
        }
        EndDrawing();
    }

    // Closes the game once the window is closed
    CloseWindow();
    return 0;

}