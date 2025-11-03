#include "types.h"

void levelHandler(struct Game* game, struct Player* player, struct Bullet bullets[], struct Asteroid** asteroidHead)
{
  switch(game->gameState)
  {
    case RESETLEVEL:
    {
      //delete the linked list
      freeAsteroidList(*asteroidHead);

      //initialise the head
      *asteroidHead = NULL;

      //initialise the linked list
      initialiseLevel("levels/level1.csv", asteroidHead);
      
      //reset player's position
      player->playerPos = (Vector2){300.f, 280.f};

      //reset bullets
      deactivateBullets(bullets, game);

      //set game state to playing
      game->gameState = PLAYING;
      
    } break;

    default: break;
  
  }

}
