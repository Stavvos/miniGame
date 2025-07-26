#include "raylib.h"

int main(void)
{
    //window setup
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();	
    InitWindow(screenWidth, screenHeight, "game");
    SetTargetFPS(60);
    HideCursor();
    
    //this texture has to be declared after the InitWindow() call due to open gl
    Texture2D player = LoadTexture("assets/sprite/player/player.png");

    SetTargetFPS(60);
    HideCursor();

    typedef enum GameScreen {MENU, GAMEPLAY} GameScreen;
    GameScreen currentScreen = MENU;
   
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //Update your variables here
        switch(currentScreen)
	{
          case MENU:
          {
	    if(IsKeyPressed(KEY_ENTER))
	    {
	      currentScreen = GAMEPLAY;
	    }
	  } break;

	  case GAMEPLAY:
	  {
	    if(IsKeyPressed(KEY_ENTER))
	    {
	      currentScreen = MENU;
	    }
	  } break; 
	  
	  default: break;
	}	

	// Draw
        BeginDrawing();
	  
	  switch(currentScreen)
	  {
	    case MENU:
	    {
              ClearBackground(BLACK);
	      DrawText("Press Enter to start the game.", 400, 400, 14, WHITE);
	    } break;	   
	    
	    case GAMEPLAY:
	    {
	      ClearBackground(RAYWHITE);
	      DrawTexture(player, 300.f, 280.f, WHITE);
	    }  break;
	   
	    default: break;
	  }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
