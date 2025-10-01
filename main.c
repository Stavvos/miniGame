#include "raylib.h"
#include "math.h"
#include "stdio.h"
#include "types.h"
#include "controls.c"
#include "screens.c"
#include "movement.c"
#include "render.c"
#include "collision.c"
#include "testing.c"
#include "asteroidMovement.c"

void initPlayer(struct Player* player)
{
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
  
  //multiply the up, down, left, etc, vectors by 15 
  player->knockBack = (Vector2){0, 15};
  player->knockUp = (Vector2){0, -15};
  player->knockLeft = (Vector2){-15, 0};
  player->knockRight = (Vector2){15, 0};
  
  //10.605 = 15 * 0.707, i.e the magic number for moving diagonal is 0.707. 
  player->knockDownLeft = (Vector2){-10.605, 10.605};
  player->knockDownRight = (Vector2){10.605, 10.605};
  player->knockUpLeft = (Vector2){-10.605, -10.605};
  player->knockUpRight = (Vector2){10.605, -10.605};

  player->playerPos = (Vector2){300.f, 280.f};
  
  player->playerHitBox.x = player->playerPos.x;
  player->playerHitBox.y = player->playerPos.y;
  player->playerHitBox.width = 8;
  player->playerHitBox.height = 9;

  player->playerTexture = LoadTexture("assets/sprite/player/ship.png");

  player->collisionState = NOTHITTING;
}

void initAsteroids(struct SmallAsteroid* smallAsteroid, struct MediumAsteroid* mediumAsteroid, struct LargeAsteroid* largeAsteroid, struct SmallAsteroid smallAsteroids[])
{
  smallAsteroid->texture = LoadTexture("assets/sprite/world/asteroid.png");
  smallAsteroid->position = (Vector2){100.f, 100.f};
  smallAsteroid->hitBox.width = 16;
  smallAsteroid->hitBox.height = 16;
  smallAsteroid->hitBox.x = smallAsteroid->position.x;
  smallAsteroid->hitBox.y = smallAsteroid->position.y;
  
  int offsetX = 20;
  int offsetY = 50;

  for(int i = 0; i < 4; i++)
  {
    smallAsteroids[i].texture = LoadTexture("assets/sprite/world/asteroid.png");
    smallAsteroids[i].position = (Vector2){100.f + offsetX, 100.f + offsetY};
    smallAsteroids[i].hitBox.width = 16;
    smallAsteroids[i].hitBox.height = 16;
    smallAsteroids[i].hitBox.x = smallAsteroid->position.x;
    smallAsteroids[i].hitBox.y = smallAsteroid->position.y;

    offsetX += 20;
    offsetY += 50;
  } 

  mediumAsteroid->texture = LoadTexture("assets/sprite/world/asteroidMedium.png");
  mediumAsteroid->position = (Vector2){200.f, 600.f};
  mediumAsteroid->hitBox.width = 32;
  mediumAsteroid->hitBox.height = 32;
  mediumAsteroid->hitBox.x = mediumAsteroid->position.x;
  mediumAsteroid->hitBox.y = mediumAsteroid->position.y;
  
  largeAsteroid->texture = LoadTexture("assets/sprite/world/asteroidLarge.png");
  largeAsteroid->position = (Vector2){920.f, 510.f};
  largeAsteroid->hitBox.width = 65;
  largeAsteroid->hitBox.height = 65;
  largeAsteroid->hitBox.x = largeAsteroid->position.x;
  largeAsteroid->hitBox.y = largeAsteroid->position.y;
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

  struct SmallAsteroid smallAsteroid;
  struct MediumAsteroid mediumAsteroid;
  struct LargeAsteroid largeAsteroid;
  struct SmallAsteroid smallAsteroids[4];
  initAsteroids(&smallAsteroid, &mediumAsteroid, &largeAsteroid, smallAsteroids);

  struct Screen screen;
  screen.gameScreen = MENU;
    
  struct Game game;
  game.gameState = PLAYING;

  // Main game loop
  while (game.gameState == PLAYING) 
  {
    //state handling
    screenHandler(&screen, &game); 
    controlsHandler(&player);        
    collisionHandler(&player, &smallAsteroid, &mediumAsteroid, &largeAsteroid);
    knockBack(&player, &screen);
    movementHandler(&player, &screen);
    updatePlayerHitBox( &player);
    
    moveAsteroid(&smallAsteroid, smallAsteroids, &player, &screen);
    
    //print states to console
    printf("Move-state:%s Collision-state:%s \n", getPlayerMoveStateString(player.playerMoveState),
		                                  getPlayerCollisionStateString(player.collisionState));
    
    DrawFPS(0,0);

    //Draw
    BeginDrawing();
      render(&screen, &player, &smallAsteroid, &mediumAsteroid, &largeAsteroid, smallAsteroids);
    EndDrawing();
  }

  // De-Initialization
  CloseWindow();        // Close window and OpenGL context
  return 0;
}
