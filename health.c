#include "types.h"

void updatePlayerHealth(struct Player* player)
{
  //reset players health 
  if(player->playerHealth == 0)
  {
    player->playerHealth = 5;
    player->playerLives--;
  }
}
