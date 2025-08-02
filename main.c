#include "raylib.h"
#include "math.h"
#include "stdio.h"
#define M_PI 3.14159265358979323846

int main(void)
{
    //window setup
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();	
    InitWindow(screenWidth, screenHeight, "game");
    SetTargetFPS(60);
    HideCursor();
    
    //player variables
    Vector2 playerPos = {300.f, 280.f};
    float playerRotation = M_PI / 4;
    float playerRotationState = 0.0f;
    float playerScale = 1.0f;

    //this texture has to be declared after the InitWindow() call due to open gl
    Texture2D player = LoadTexture("assets/sprite/player/ship.png");
    Texture2D asteroid = LoadTexture("assets/sprite/world/asteroid.png");
    Texture2D asteroidMedium = LoadTexture("assets/sprite/world/asteroidMedium.png");
    Texture2D asteroidLarge = LoadTexture("assets/sprite/world/asteroidLarge.png");
    SetTargetFPS(60);
    HideCursor();

    typedef enum GameScreen {MENU, GAMEPLAY} GameScreen;
    GameScreen currentScreen = MENU;

    typedef enum GameState {PLAYING, EXIT} GameState;
    GameState currentState = PLAYING; 
    
    // Main game loop
    while (currentState != EXIT) 
    {
        //Update game 
        switch(currentScreen)
	{
          case MENU:
          {
	    if(IsKeyPressed(KEY_ENTER))
	    {
	      currentScreen = GAMEPLAY;
	    }

	    if(IsKeyPressed(KEY_ESCAPE))
	    {
	      currentState = EXIT;
	    }
	  } break;

	  case GAMEPLAY:
	  {
	    if(IsKeyPressed(KEY_ESCAPE))
	    {
	      currentScreen = MENU;
	    }
	  } break;
	  
	  default: break;
	}	
        
        //move forward 	
	if(IsKeyDown(KEY_W)) {
	  playerPos.y -= 0.5f; 
	}
        
	//move down
        if(IsKeyDown(KEY_S)) {
	  playerPos.y += 0.5f; 
	}
        
        //rotate the player sprite right	
        if(IsKeyDown(KEY_D)) {	
	    playerRotationState += playerRotation;  
	}
	
	//rotate the player sprite left	
        if(IsKeyDown(KEY_A)) {	
	  playerRotationState -= playerRotation; 	
	}
	
	//handle normalising the playerRotationState value to between 0-360 
	if (playerRotationState >= 360){
	  playerRotationState -= 360;
	}
	else if (playerRotationState < 0){
	  playerRotationState  += 360;
	}
	
	
	printf("%f\n",  playerRotationState); 

	//Draw
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
	      DrawTextureEx(player, playerPos, playerRotationState, playerScale, WHITE); 
	      //DrawTexture(player, playerPos.x, playerPos.y, WHITE); 
	      DrawTexture(asteroid, 100.f, 100.f, WHITE);
	      DrawTexture(asteroidMedium, 200.f, 600.f, WHITE);
	      DrawTexture(asteroidLarge, 920.f, 510.f, WHITE);
	    }  break;
	   
	    default: break;
	  }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}
