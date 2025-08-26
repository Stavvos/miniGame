#include "raylib.h"
#include "math.h"
#include "stdio.h"


//placed this up here to enable printing player state 
typedef enum PlayerMoveState {MOVEFORWARD, MOVEBACKWARD, MOVELEFT, MOVERIGHT, NOMOVE} PlayerMoveState;
PlayerMoveState playerMoveState = NOMOVE; 

//used to print a meaningful player state rather than a number
const char* getPlayerMoveStateString(PlayerMoveState state){
  switch (state) 
  {
    case MOVEFORWARD: return "MOVEFORWARD";
    case MOVEBACKWARD: return "MOVEBACKWARD";
    case MOVELEFT: return "MOVELEFT";
    case MOVERIGHT: return "MOVERIGHT";
    case NOMOVE: return "NOMOVE";
    default: return "NULLSTATE";
  }	
}	
	

int main(void)
{
    //window setup
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();	
    InitWindow(screenWidth, screenHeight, "game");
    SetTargetFPS(60);
    HideCursor();
    
    Vector2 moveUp = {0, -1};
    Vector2 moveDown = {0, 1};
    Vector2 moveLeft = {-1, 0};
    Vector2 moveRight = {1, 0};

    //player variables
    Vector2 playerPos = {300.f, 280.f};

    //texture has to be declared after the InitWindow() call due to open gl
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
        //Update game screen state 
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
       
	//Update player move state 
        switch(playerMoveState)
	{
          case NOMOVE:
          {
 	    //move forward 	
	    if(IsKeyDown(KEY_W)) {
	      playerMoveState = MOVEFORWARD;
	    }
        
	    //move down
            if(IsKeyDown(KEY_S)) {
	      playerMoveState = MOVEBACKWARD;
	    }
        
           //move right	
           if(IsKeyDown(KEY_D)) {
	      playerMoveState = MOVERIGHT;
	    }
	
	   //move left	
           if(IsKeyDown(KEY_A)) {
	      playerMoveState = MOVELEFT;
	    }
  
	 } break;
	 
	  case MOVEFORWARD:
          {
 	    //move forward 	
	    if(IsKeyDown(KEY_W)) {
	      playerPos.x = playerPos.x + moveUp.x;
	      playerPos.y = playerPos.y + moveUp.y; 
	    }
        
	    //move down
            if(IsKeyDown(KEY_S)) {
	      playerMoveState = MOVEBACKWARD;
	    }
        
           //move diag right	
           if(IsKeyDown(KEY_D)) {
	      playerMoveState = MOVERIGHT;
	    }
	
	   //move diag left	
           if(IsKeyDown(KEY_A)) {
	      playerMoveState = MOVELEFT;
	    }
 	  
	   //no move 	
           if(IsKeyUp(KEY_W)) {
	      playerMoveState = NOMOVE;
	    }
 
	  } break;

	  case MOVEBACKWARD:
          {
 	    //move forward 	
	    if(IsKeyDown(KEY_W)) {
	      playerMoveState = MOVEFORWARD;
	    }
        
	    //move down
            if(IsKeyDown(KEY_S)) {
	      playerPos.x = playerPos.x + moveDown.x;
	      playerPos.y = playerPos.y + moveDown.y;
	    }
         
	   //no move 	
	    if (IsKeyUp(KEY_S)){  
	      playerMoveState = NOMOVE;
	    }
 	   
	  } break;


	  case MOVELEFT:
          {
 	    //move forward 	
	    if(IsKeyDown(KEY_W)) {
	      playerMoveState = MOVEFORWARD;
	    }
        
	    //move down
            if(IsKeyDown(KEY_S)) {
	      playerMoveState = MOVEBACKWARD;
	    }
        
           //move right	
           if(IsKeyDown(KEY_D)) {
	      playerMoveState = MOVERIGHT;
	    }
	
	   //move left	
           if(IsKeyDown(KEY_A)) {
              playerPos.x = playerPos.x + moveLeft.x; 
  	      playerPos.y = playerPos.y + moveLeft.y; 	  
	    }
 	  
	   //no move 	
           if(IsKeyUp(KEY_A)) {
	      playerMoveState = NOMOVE;
	    }
 
	  } break;

	  case MOVERIGHT:
          {
 	    //move forward 	
	    if(IsKeyDown(KEY_W)) {
	      playerMoveState = MOVEFORWARD;
	    }
        
	    //move down
            if(IsKeyDown(KEY_S)) {
	      playerMoveState = MOVEBACKWARD;
	    }
        
           //move right	
           if(IsKeyDown(KEY_D)) {
              playerPos.x = playerPos.x + moveRight.x;
  	      playerPos.y = playerPos.y + moveRight.y; 	  
	    }
	
	   //move left	
           if(IsKeyDown(KEY_A)) {
	      playerMoveState = MOVELEFT;
	    }
 	  
	   //no move 	
           if(IsKeyUp(KEY_D)) {
	      playerMoveState = NOMOVE;
	    }
 
	  } break;

	  default: break;
	 
	}
        
       
	//print the player's current move state
	printf("%s \n", getPlayerMoveStateString(playerMoveState));

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
	      DrawTexture(player, playerPos.x, playerPos.y, WHITE); 
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
