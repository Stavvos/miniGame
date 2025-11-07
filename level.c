#include "types.h"

void levelChangeHandler(struct Asteroid** head, struct Game* game, struct Screen* gameScreen)
{
  struct Asteroid* current = *head;
  
  //if no asteroids in linked list
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
      //delete the linked list
      freeAsteroidList(*asteroidHead);

      //initialise the head
      *asteroidHead = NULL;

      //initialise the linked list
      initialiseLevel(levelFileNames[game->level], asteroidHead);
           
      //reset player's position
      player->playerPos = (Vector2){300.f, 280.f};

      //reset bullets
      deactivateBullets(bullets, game);
      
      //reset explosions
      resetExplosions(explosions);

      //set game state to playing
      game->gameState = PLAYING;
      
    } break;

    case NEXTLEVEL:
    {
      //delete the linked list
      freeAsteroidList(*asteroidHead);

      //initialise the head
      *asteroidHead = NULL;

      //initialise the linked list
      initialiseLevel(levelFileNames[game->level], asteroidHead);
      
      //reset player's position
      player->playerPos = (Vector2){300.f, 280.f};

      //reset bullets
      deactivateBullets(bullets, game);
      
      //reset explosions
      resetExplosions(explosions);

      //set game state to playing
      game->gameState = PLAYING;
    
    } break;

    case ENDGAME:
    {
      //delete the linked list
      freeAsteroidList(*asteroidHead);

      //initialise the head
      *asteroidHead = NULL;

      //initialise the linked list
      initialiseLevel(levelFileNames[game->level], asteroidHead);
      
      //reset player's position and score
      player->playerPos = (Vector2){300.f, 280.f};

      //reset bullets
      deactivateBullets(bullets, game);
      
      //reset explosions
      resetExplosions(explosions);

      //set game state to playing
      game->gameState = PLAYING;
    
    } break;
    
      default: break;
  }

}
