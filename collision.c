#include "raylib.h"
#include "types.h"

void deleteAsteroid(asteroid* current, asteroid* previous, asteroid** head)
{
  //remove the head of the linked list
  if(previous == NULL)
  {
    *head = current->next;
    free(current);
  }
  else //remove other node of the linked list
  {
    previous->next = current->next;
    free(current);
  }
}

void collisionHandler(struct Player* player, struct Game* game, asteroid** head)
{
 
  asteroid* current = *head;
  asteroid* previous = NULL;
  
  while(current != NULL)
  {
    if (CheckCollisionRecs(player->playerHitBox, current->hitBox))
    {
      player->collisionState = HITTING;
      
      if (player->playerHealth > 0)
      {
        player->playerHealth--;      
      }
      
      asteroid* next = current->next;
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

void bulletHitAsteroid(asteroid** head, struct Bullet bullets[], struct Game* game)
{
 
  for(int i = 0; i < game->MAXBULLETS; i++)
  {
    asteroid* current = *head;
    asteroid* previous = NULL;
 
    if(bullets[i].active)
    {
      while(current != NULL)
      {
        if (CheckCollisionRecs(bullets[i].hitBox, current->hitBox))
        {
          asteroid* next = current->next;
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
