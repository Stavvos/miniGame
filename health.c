#include "types.h"

void resetPlayerHealth(struct Player* player)
{
  if (player->playerHealth == 0)
  {
    player->playerHealth = PLAYERHEALTH;
    player->playerLives--;
    player->invulnFrames = INVULNFRAMES;
  }
}
