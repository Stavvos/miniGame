#include "types.h"

void decrementPlayerHealth(struct Player* player)
{
  if (player->playerHealth > 0)
  {
    player->playerHealth -= player->hitTally;
    player->hitTally = 0;
  }
}

void resetPlayerHealth(struct Player* player)
{
  if (player->playerHealth == 0)
  {
    player->playerHealth = PLAYERHEALTH;
    player->playerLives--;
    player->invulnFrames = INVULNFRAMES;
  }
  else if (player->playerHealth < 0)
  {
    player->playerHealth = PLAYERHEALTH + player->playerHealth;
    player->playerLives--;
    player->invulnFrames = INVULNFRAMES;
  }
}
