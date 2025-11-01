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
      *asteroidHead = (struct Asteroid*) malloc(sizeof(struct Asteroid));

      //initialise the linked list
      initAsteroids(*asteroidHead);

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
