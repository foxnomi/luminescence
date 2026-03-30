#include <raylib.h>
#include "debugConsole.h"

using namespace std;

// TO DO: Re-Do Console so less memory is used up, create a tick list so that its easier to manage order of things to do (with prio)
// Make sure to add being able to actually run things in the console too!!!
// After that pretty much just start working on the damn game lol

// Alpha 1.0

int main(void) {
    // Setup vars, such as window and fps parameters
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Luminescence Alpha 1.0");
    SetWindowState(FLAG_FULLSCREEN_MODE);
    SetTargetFPS(60);

    // Class vars and important vars
    debugConsole console;

    // The main game loop
    while(!WindowShouldClose()) {
        // Right here is where all the ACTUAL code updating goes

        BeginDrawing(); // Start the screen updating
            ClearBackground(BLACK);
        EndDrawing();
    }

    // Closes the game once the window is closed
    CloseWindow();
    return 0;

}