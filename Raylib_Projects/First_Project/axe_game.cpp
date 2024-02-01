#include "raylib.h"

struct Axe
{
    // X and Y coordinates correspond to upper left corner
    int x;
    int y;
    int direction;
    int length;
};

struct Player
{
    int x;
    int y;
    int radius;
};

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

bool checkCollision(const Player &player, const Axe &axe) // use const reference since we aren't altering values
{
    // Player Hitbox Edges
    int left_player_x = player.x - player.radius;
    int right_player_x = player.x + player.radius;
    int upper_player_y = player.y - player.radius;
    int bottom_player_y = player.y + player.radius;

    // Axe Hitbox Edges
    int left_axe_x = axe.x;
    int right_axe_x = axe.x + axe.length;
    int upper_axe_y = axe.y;
    int bottom_axe_y = axe.y + axe.length;

    bool horizontal_overlap = left_axe_x <= right_player_x && right_axe_x >= left_player_x;
    bool vertical_overlap = upper_axe_y <= bottom_player_y && bottom_axe_y >= upper_player_y;

    return horizontal_overlap && vertical_overlap;
}

void handleGameOver(int screen_pos_x, int screen_pos_y)
{
    DrawText("Game Over!", screen_pos_x, screen_pos_y, 20, RED);
    DrawText("Press _Space_ to Exit", screen_pos_x, (screen_pos_y + 25), 10, RED);
    EndDrawing();
}

main()
{
    // Assign window dimmensions and build
    int width{640};
    int height{480};
    int centerX{width / 2};
    int centerY{height / 2};
    InitWindow(width, height, "Test Window");

    // Derfine Player propeties
    Player player = {35, centerY, 25};

    // Axe properties
    Axe axe1 = {100, 50, 12, 50};
    Axe axe2 = {200, (height - 50), 12, 50};
    Axe axe3 = {300, 50, 12, 50};
    Axe axe4 = {400, (height - 50), 12, 50};

    bool gameOver = false;

    SetTargetFPS(60);
    while (!WindowShouldClose() && !gameOver)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        // Begining of game

        // Draw player
        DrawCircle(player.x, player.y, player.radius, BLUE);

        // Draw Axes
        DrawRectangle(axe1.x, axe1.y, axe1.length, axe1.length, PURPLE);
        DrawRectangle(axe2.x, axe2.y, axe2.length, axe2.length, PURPLE);
        DrawRectangle(axe3.x, axe3.y, axe3.length, axe3.length, PURPLE);
        DrawRectangle(axe4.x, axe4.y, axe4.length, axe4.length, PURPLE);

        // Move Axes
        moveAxe(axe1.y, axe1.direction, height);
        moveAxe(axe2.y, axe2.direction, height);
        moveAxe(axe3.y, axe3.direction, height);
        moveAxe(axe4.y, axe4.direction, height);

        handleMovement(player.x, width);

        if (checkCollision(player, axe1))
        {
            handleGameOver(centerX, centerY);
            // Wait for user input before closing the window
            while (!WindowShouldClose())
            {
                // Check if any key is pressed
                if (IsKeyPressed(KEY_SPACE))
                {
                    break;
                }
            }
            gameOver = true;
        }
        else
        {
            // End of game
            EndDrawing();
        }
    }
    CloseWindow();
    return 0;
}
