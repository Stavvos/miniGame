#include "types.h"

void updatePlayerHealth(struct Player* player)
{
  //reset players health 
  if(player->playerHealth == 0)
  {
    player->playerHealth = PLAYERHEALTH;
    player->playerLives--;
    player->invulnFrames = INVULNFRAMES;
  }
}
