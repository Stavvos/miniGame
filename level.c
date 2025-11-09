#include "types.h"

void levelChangeHandler(struct Asteroid** head, struct Game* game, struct Screen* gameScreen)
{
  struct Asteroid* current = *head;
  
  if(current == NULL) 
  {
    if(game->level < game->MAXLEVEL)
    {
      game->level++;
      game->gameState = RESETLEVEL;
      gameScreen->gameScreen = WONLEVEL;
    }
    else
    {
      game->gameState = ENDGAME;
      gameScreen->gameScreen = WONGAME;
      game->level = 0;
    }
  }
}

void levelHandler(struct Game* game, struct Player* player, struct Bullet bullets[], struct Asteroid** asteroidHead, char* levelFileNames[], struct Explosion explosions[])
{
  switch(game->gameState)
  {
    case RESETLEVEL:
    {
      freeAsteroidList(*asteroidHead);
      *asteroidHead = NULL;
      initialiseLevel(levelFileNames[game->level], asteroidHead);
      player->playerPos = (Vector2){300.f, 280.f};
      deactivateBullets(bullets, game);
      resetExplosions(explosions);
      game->gameState = PLAYING;
    } break;

    case NEXTLEVEL:
    {
      freeAsteroidList(*asteroidHead);
      *asteroidHead = NULL;
      initialiseLevel(levelFileNames[game->level], asteroidHead);
      player->playerPos = (Vector2){300.f, 280.f};
      deactivateBullets(bullets, game);
      resetExplosions(explosions);
      game->gameState = PLAYING;
    } break;

    case ENDGAME:
    {
      freeAsteroidList(*asteroidHead);
      *asteroidHead = NULL;
      initialiseLevel(levelFileNames[game->level], asteroidHead);
      player->playerPos = (Vector2){300.f, 280.f};
      deactivateBullets(bullets, game);
      resetExplosions(explosions);
      game->gameState = PLAYING;
    } break;
    
      default: break;
  }
}
