#include "raylib.h"

void handleMovement(int &x) // reference to x to prevent taking an uneccessary copy
{
    // Move circle right
    if (IsKeyDown(KEY_D) && x < 640)
    {
        x += 3.5;
    }
    // Move circle left
    if (IsKeyDown(KEY_A) && x > 0)
    {
        x -= 3.5;
    }
}

int main()
{
    // Assign window dimmensions and build
    int width{640};
    int height{480};
    InitWindow(width, height, "Test Window");

    // Circle coordinates
    int circleX{320};
    int circleY{240};

    // Axe coordinates
    int axeX{150};
    int axeY{150};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        // Begining of game

        DrawCircle(circleX, circleY, 25, BLUE);
        DrawRectangle(axeX, axeY, 50, 50, GREEN);

        // Move axe
        axeY += 10;

        handleMovement(circleX);

        // End of game
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
