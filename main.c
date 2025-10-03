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

void initAsteroids(struct SmallAsteroid smallAsteroids[], struct MediumAsteroid mediumAsteroids[], struct LargeAsteroid largeAsteroids[], struct Game* game)
{
  
  Texture2D smallAsteroidTexture = LoadTexture("assets/sprite/world/asteroid.png");
  Texture2D mediumAsteroidTexture = LoadTexture("assets/sprite/world/asteroidMedium.png");
  Texture2D largeAsteroidTexture = LoadTexture("assets/sprite/world/asteroidLarge.png");

  int offsetX = 20;
  int offsetY = 50;

  for(int i = 0; i < game->SMALLASTEROIDCOUNT; i++)
  {
    smallAsteroids[i].texture = smallAsteroidTexture; 
    smallAsteroids[i].position = (Vector2){100.f + offsetX, 100.f + offsetY};
    smallAsteroids[i].hitBox.width = 16;
    smallAsteroids[i].hitBox.height = 16;
    smallAsteroids[i].hitBox.x = smallAsteroids[i].position.x;
    smallAsteroids[i].hitBox.y = smallAsteroids[i].position.y;

    offsetX += 20;
    offsetY += 50;
  } 
  
  offsetX = 0;
  offsetY = 0;

  for (int i = 0; i < game->MEDIUMASTEROIDCOUNT; i++)
  {
    mediumAsteroids[i].texture = mediumAsteroidTexture;
    mediumAsteroids[i].position = (Vector2){200.f + offsetX, 600.f + offsetY};
    mediumAsteroids[i].hitBox.width = 32;
    mediumAsteroids[i].hitBox.height = 32;
    mediumAsteroids[i].hitBox.x = mediumAsteroids[i].position.x;
    mediumAsteroids[i].hitBox.y = mediumAsteroids[i].position.y;
    
    offsetX += 50;
    offsetY -= 20;
  }
  
  offsetX = 0;
  offsetY = 0;

  for (int i = 0; i < game->LARGEASTEROIDCOUNT; i++)
  {
    largeAsteroids[i].texture = largeAsteroidTexture;
    largeAsteroids[i].position = (Vector2){920.f + offsetX, 510.f + offsetY};
    largeAsteroids[i].hitBox.width = 65;
    largeAsteroids[i].hitBox.height = 65;
    largeAsteroids[i].hitBox.x = largeAsteroids[i].position.x;
    largeAsteroids[i].hitBox.y = largeAsteroids[i].position.y;

    offsetX += 100;
    offsetY -= 20;
  }
}

void initGame(struct Game* game)
{
  game->SMALLASTEROIDCOUNT = 600;
  game->MEDIUMASTEROIDCOUNT = 4;
  game->LARGEASTEROIDCOUNT = 2;
  game->gameState = PLAYING;
}

int main(void)
{
  const int screenWidth = GetScreenWidth();
  const int screenHeight = GetScreenHeight();	
  InitWindow(screenWidth, screenHeight, "game");
  SetTargetFPS(60);
  HideCursor();

  struct Player player;
  initPlayer(&player);
  
  struct Game game;
  initGame(&game);

  struct SmallAsteroid smallAsteroids[game.SMALLASTEROIDCOUNT];
  struct MediumAsteroid mediumAsteroids[game.MEDIUMASTEROIDCOUNT];
  struct LargeAsteroid largeAsteroids[game.LARGEASTEROIDCOUNT];
  initAsteroids(smallAsteroids, mediumAsteroids, largeAsteroids, &game);

  struct Screen screen;
  screen.gameScreen = MENU;
    
  // Main game loop
  while (game.gameState == PLAYING) 
  {
    //state handling
    screenHandler(&screen, &game); 
    controlsHandler(&player);        
    playerMovementHandler(&player, &screen);
    updatePlayerHitBox(&player);
    moveAsteroids(smallAsteroids, mediumAsteroids, largeAsteroids, &player, &screen, &game);
    collisionHandler(&player, &game, smallAsteroids, mediumAsteroids, largeAsteroids);
    
    //knockBack(&player, &screen);
    
    //print states to console
    printf("Move-state:%s Collision-state:%s \n", getPlayerMoveStateString(player.playerMoveState),
 		                                  getPlayerCollisionStateString(player.collisionState));
    
    //Draw
    BeginDrawing();
      DrawFPS(0,0);
      render(&screen, &player, &game, smallAsteroids, mediumAsteroids, largeAsteroids);
    EndDrawing();

    //reset states
    collisionCleanup(&player);
  }

  // De-Initialization
  CloseWindow();        // Close window and OpenGL context
  return 0;
}
