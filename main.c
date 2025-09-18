#include "raylib.h"
#include "math.h"
#include "stdio.h"
#include "types.h"
#include "controls.c"
#include "screens.c"
#include "movement.c"
#include "render.c"

//used to print a meaningful player state rather than a number
const char* getPlayerMoveStateString(PlayerMoveState state){
  switch (state) 
  {
    case MOVEFORWARD: return "MOVEFORWARD";
    case MOVEBACKWARD: return "MOVEBACKWARD";
    case MOVELEFT: return "MOVELEFT";
    case MOVERIGHT: return "MOVERIGHT";
    case NOMOVE: return "NOMOVE";
    case MOVEUPRIGHT: return "MOVEUPRIGHT";
    case MOVEUPLEFT: return "MOVEUPLEFT";
    case MOVEDOWNRIGHT: return "MOVEDOWNRIGHT";
    case MOVEDOWNLEFT: return "MOVEDOWNLEFT";
    default: return "NULLSTATE";
  }	
}	

void initPlayer(struct Player* player)
{
  //struct Player player;
  player->moveUp = (Vector2){0, -1};
  player->moveDown = (Vector2){0, 1};
  player->moveLeft = (Vector2){-1, 0};
  player->moveRight = (Vector2){1, 0};

  //these values are set to 0.707 as an approximate value for handling diagonal movement.
  //the key to these values being useful lies within the pythagoras theorum a^2 + b^2 = c^2
  //think of the hypotenuse of a right sided triangle
  //
  //for example: if you add the up vector (1 movement up) and the left vector(1 movement left) for 
  //up left movement the player's speed is too fast by approximately 40%. the value 0.707 handles this well. 
  player->moveUpRight = (Vector2){0.707, -0.707};
  player->moveUpLeft = (Vector2){-0.707, -0.707};
  player->moveDownRight = (Vector2){0.707, 0.707};
  player->moveDownLeft = (Vector2){-0.707, 0.707};
    
  player->playerPos = (Vector2){300.f, 280.f};
    
  player->playerTexture = LoadTexture("assets/sprite/player/ship.png");
}

void initEnemy(struct Enemy* enemy)
{
  enemy->asteroidSmall = LoadTexture("assets/sprite/world/asteroid.png");
  enemy->asteroidMedium = LoadTexture("assets/sprite/world/asteroidMedium.png");
  enemy->asteroidLarge = LoadTexture("assets/sprite/world/asteroidLarge.png");
}

int main(void)
{
  //window setup
  const int screenWidth = GetScreenWidth();
  const int screenHeight = GetScreenHeight();	
  InitWindow(screenWidth, screenHeight, "game");
  SetTargetFPS(60);
  HideCursor();

  struct Player player;
  initPlayer(&player);

  struct Enemy enemy;
  initEnemy(&enemy);

  struct Screen screen;
  screen.gameScreen = MENU;
    
  struct Game game;
  game.gameState = PLAYING;
 
  // Main game loop
  while (game.gameState != EXIT) 
  {
    //state handling
    screenHandler(&screen, &game); 
    controlsHandler(&player);        
    movementHandler(&player);
    printf("%s \n", getPlayerMoveStateString(player.playerMoveState));
    
    //Draw
    BeginDrawing();
      render(&screen, &player, &enemy);
    EndDrawing();
  }

  // De-Initialization
  CloseWindow();        // Close window and OpenGL context
  return 0;
}
