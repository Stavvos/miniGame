#include "types.h"

void flipPlayerRenderBool(struct Player* player)
{
  if(player->invulnFrames % 4 == 0)
  {
    player->invulnRenderPlayer = !player->invulnRenderPlayer; //flip between true or false each frame
  }
}

void updateInvulnFrames(struct Player* player)
{
  if(player->invulnFrames > 0)
  {
    player->invulnFrames--;
    flipPlayerRenderBool(player);  
  }
  else
  {
    player->invulnRenderPlayer = true;
  }
}
