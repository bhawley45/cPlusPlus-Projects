#include "raylib.h"

void handleMovement(int &x, int &windowWidth) // reference to x to prevent taking an uneccessary copy
{
    // Move circle right
    if (IsKeyDown(KEY_D) && x < windowWidth)
    {
        x += 3.5;
    }
    // Move circle left
    if (IsKeyDown(KEY_A) && x > 0)
    {
        x -= 3.5;
    }
}

void moveAxe(int &y, int &direction, int &windowHeight)
{
    if (y > windowHeight || y < 0)
    {
        direction *= -1; // Reverse direction if at window border
    }
    y += direction; // Move axe
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
    int direction{12};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        // Begining of game

        DrawCircle(circleX, circleY, 25, BLUE);
        DrawRectangle(axeX, axeY, 50, 50, GREEN);

        moveAxe(axeY, direction, height);
        handleMovement(circleX, width);

        // End of game
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
