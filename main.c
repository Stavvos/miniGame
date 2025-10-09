#include <stdlib.h>
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
  
  player->playerPos = (Vector2){300.f, 280.f};
  
  player->playerHitBox.x = player->playerPos.x;
  player->playerHitBox.y = player->playerPos.y;
  player->playerHitBox.width = 8;
  player->playerHitBox.height = 9;

  player->playerTexture = LoadTexture("assets/sprite/player/ship.png");

  player->collisionState = NOTHITTING;
}

void initGame(struct Game* game)
{
  game->gameState = PLAYING;
}

void pushAsteroidLeft(asteroid* head, Texture2D texture, int offsetX, int offsetY)
{
  asteroid* current = head;

  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = (asteroid*) malloc(sizeof(asteroid));
  current->next->texture = texture;
  current->next->position = (Vector2){100.f + offsetX, 100.f + offsetY};
  current->next->hitBox.width = 16;
  current->next->hitBox.height = 16;
  current->next->hitBox.x = current->next->position.x;
  current->next->hitBox.y = current->next->position.y;
  current->next->collisionState = NOTHITTING;
  current->next->next = NULL;
}

void freeAsteroidList(asteroid* head)
{
  printf("\n\nDe-allocating asteroid linked list memory\n");
  asteroid* current = head;
  asteroid* nextNode;
  
  while (current != NULL)
  {
      nextNode = current->next;
      free(current);
      current = nextNode;
  }

  printf("Asteroid inked list memory de-allocated\n\n");
}

void initAsteroids(asteroid* head)
{
  //linked list node test
  Texture2D smallAsteroidTexture = LoadTexture("assets/sprite/world/asteroid.png");
  head->texture = smallAsteroidTexture;
  head->position = (Vector2){100.f, 100.f};
  head->hitBox.width = 16;
  head->hitBox.height = 16;
  head->hitBox.x = head->position.x;
  head->hitBox.y = head->position.y;
  head->collisionState = NOTHITTING;
  head->next = NULL;
  
  int offsetX = 5;
  int offsetY = 5;
  for (int i = 0; i < 1000; i++)
  {
    pushAsteroidLeft(head, smallAsteroidTexture, offsetX, offsetY);
    offsetX += 5;
    offsetY += 0;
  }

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

  struct Screen screen;
  screen.gameScreen = MENU;
  
  Texture2D mediumAsteroidTexture = LoadTexture("assets/sprite/world/asteroidMedium.png");
  Texture2D largeAsteroidTexture = LoadTexture("assets/sprite/world/asteroidLarge.png");
  
  //asteroid linked list initialisation 
  asteroid* head = NULL;
  head = (asteroid*) malloc(sizeof(asteroid));
  initAsteroids(head);

  // Main game loop
  while (game.gameState == PLAYING) 
  {
    //state handling
    screenHandler(&screen, &game); 
    controlsHandler(&player);        
    playerMovementHandler(&player, &screen);
    updatePlayerHitBox(&player);
    moveAsteroids(&player, &screen, &game, head);
    collisionHandler(&player, &game, &head);
    
    //print states to console
    printf("Move-state:%s Collision-state:%s \n", getPlayerMoveStateString(player.playerMoveState),
 		                                  getPlayerCollisionStateString(player.collisionState));
        
    //Draw
    BeginDrawing();
      DrawFPS(0,0);
      render(&screen, &player, &game, head);
    EndDrawing();

    //reset states
    collisionCleanup(&player);
  }

  // De-Initialization
  freeAsteroidList(head);
  CloseWindow();        // Close window and OpenGL context
  return 0;
}
