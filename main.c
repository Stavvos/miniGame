#include "raylib.h"

int main(void)
{
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    InitWindow(screenWidth, screenHeight, "game");
    SetTargetFPS(60);
    HideCursor();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //Update your variables here
        
	// Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
