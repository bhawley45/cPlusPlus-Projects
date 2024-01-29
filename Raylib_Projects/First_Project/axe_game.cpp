#include "raylib.h";

int main()
{
    // Assign window dimmensions and build
    int width{640};
    int height{480};
    InitWindow(width, height, "Test Window");

    int circleX{320};
    int circleY{240};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        // Begining of game

        DrawCircle(circleX, circleY, 25, BLUE);

        // Move circle right
        if (IsKeyDown(KEY_D))
        {
            circleX += 3.5;
        }

        // Move circle left
        if (IsKeyDown(KEY_A))
        {
            circleX -= 3.5;
        }

        // End of game
        EndDrawing();
    }
}