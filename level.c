#include "types.h"

void levelChangeHandler(struct Asteroid** head, struct Game* game, struct Screen* screen, struct Player* player)
{
  struct Asteroid* current = *head;
  
  if(current == NULL) 
  {
    if(game->level < game->MAXLEVEL && player->playerLives >= 0)
    {
      game->level++;
      game->gameState = RESETLEVEL;
      screen->gameScreen = WONLEVEL;
    }
    else if (game->level == game->MAXLEVEL && player->playerLives >= 0)
    {
      game->gameState = ENDGAME;
      screen->gameScreen = WONGAME;
      game->level = 0;
    }
    else
    {
      game->gameState = ENDGAME;
      screen->gameScreen = GAMEOVER;   
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
