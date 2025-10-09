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

void collisionCleanup(struct Player* player)
{
  player->collisionState = NOTHITTING;
}
