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

    // Circle properties
    int circle_X{320};
    int circle_Y{240};
    int circle_Rad{25};
    // Edges
    int l_circle_X{circle_X - circle_Rad};
    int r_circle_X{circle_X + circle_Rad};
    int u_circle_Y{circle_Y - circle_Rad};
    int b_circle_Y{circle_Y + circle_Rad};

    // Axe properties
    int axe_X{150};
    int axe_Y{150};
    int axe_Dir{12};
    int axe_Len{50};
    // Edges
    int l_axe_X{axe_X};
    int r_axe_X{axe_X + axe_Len};
    int u_axe_Y{axe_Y};
    int b_axe_Y{axe_Y + axe_Len};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        // Begining of game

        DrawCircle(circle_X, circle_Y, circle_Rad, BLUE);
        DrawRectangle(axe_X, axe_Y, axe_Len, axe_Len, GREEN);

        moveAxe(axe_Y, axe_Dir, height);
        handleMovement(circle_X, width);

        // End of game
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
