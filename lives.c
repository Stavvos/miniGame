#include "types.h"

void updatePlayerLives(struct Player* player, struct Screen* screen)
{
  //transition to gameover screen 
  if(player->playerLives == -1)
  {
    screen->gameScreen = GAMEOVER;
  }
}
