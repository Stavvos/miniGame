#include "types.h"

void handlePlayerDeath(struct Player* player, struct Screen* screen)
{
  if(player->playerLives == -1)
  {
    screen->gameScreen = GAMEOVER;
  }
}
