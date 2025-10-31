#include "raylib.h"
#include "types.h"

void collisionHandler(struct Player* player, struct Game* game, struct Asteroid** head)
{
 
  struct Asteroid* current = *head;
  struct Asteroid* previous = NULL;
  
  while(current != NULL)
  {
    if (CheckCollisionRecs(player->playerHitBox, current->hitBox))
    {
      player->collisionState = HITTING;
      
      if (player->playerHealth > 0)
      {
        player->playerHealth--;      
      }
      
      struct Asteroid* next = current->next;
      deleteAsteroid(current, previous, head);
      current = next;
    }
    else //no collision found, move onto the node
    {
      previous = current;
      current = current->next;
    }
  }

}

void bulletHitAsteroid(struct Asteroid** head, struct Bullet bullets[], struct Game* game)
{
 
  for(int i = 0; i < game->MAXBULLETS; i++)
  {
    struct Asteroid* current = *head;
    struct Asteroid* previous = NULL;
 
    if(bullets[i].active)
    {
      while(current != NULL)
      {
        if (CheckCollisionRecs(bullets[i].hitBox, current->hitBox))
        {
          struct Asteroid* next = current->next;
          deleteAsteroid(current, previous, head);
          current = next;
        }
        else //no collision found, move onto the node
        {
          previous = current;
          current = current->next;
        }
      }
    }
  }
}

void collisionCleanup(struct Player* player)
{
  player->collisionState = NOTHITTING;
}
