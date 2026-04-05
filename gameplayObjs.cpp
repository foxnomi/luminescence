#include <raylib.h>
#include <string>
#include <cmath>

using namespace std;

class GameplayObjs { // Parent for all gameplay objects
    public:
        string objType;

        void virtual tick(){}
        void virtual draw(){}
};

// BIG NOTE HERE!!!!!
// Make sure to add override to the functions in child classes or else I'll fucking die
// 4/16 11:39pm

class Player : public GameplayObjs { // Player object
    public:
        int worldx = GetScreenWidth() / 2;
        int worldy = GetScreenHeight() / 2;
        float dx = 0;
        float dy = 0;
        int speed = 50;

        Player() { // Constructor
            objType = "Player";
        }

        void tick() override { // What happens during the player tick
            move();
        }

        void draw() override { // Stuff drawn on screen during the draw phase
            DrawRectangle(worldx, worldy, 40, 40, WHITE);
        }

        void move() { // Player movement
            float moveSpeed = speed * GetFrameTime();
            if (IsKeyDown(KEY_D)) {
                dx += moveSpeed;
            }
            if (IsKeyDown(KEY_A)) {
                dx -= moveSpeed;
            }
            if (IsKeyDown(KEY_W)) {
                dy -= moveSpeed;
            }
            if (IsKeyDown(KEY_S)) {
                dy += moveSpeed;
            }
            worldx += round(dx);
            worldy += round(dy);
            dx *= .8;
            dy *= .8;
        }
};