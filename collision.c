#include "raylib.h"
#include "types.h"

void collisionHandler(struct Player* player, struct SmallAsteroid* smallAsteroid, struct MediumAsteroid* mediumAsteroid, struct LargeAsteroid* largeAsteroid)
{
  if (CheckCollisionRecs(player->playerHitBox, smallAsteroid->hitBox))
  {
    player->collisionState = HITTING;
  }
  else if (CheckCollisionRecs(player->playerHitBox, mediumAsteroid->hitBox))
  {
    player->collisionState = HITTING;
  }
  else if (CheckCollisionRecs(player->playerHitBox, largeAsteroid->hitBox))
  {
    player->collisionState = HITTING;
  }
  else
  {
    player->collisionState = NOTHITTING;
  }
}

void knockBack(struct Player* player, struct Screen* screen)
{
  if (screen->gameScreen == GAMEPLAY && player->collisionState == HITTING && player->playerMoveState == MOVEFORWARD)
  {
    player->playerPos.x = player->playerPos.x + player->knockBack.x;
    player->playerPos.y = player->playerPos.y + player->knockBack.y;
  }
  else if (screen->gameScreen == GAMEPLAY && player->collisionState == HITTING && player->playerMoveState == MOVEBACKWARD)
  {
    player->playerPos.x = player->playerPos.x + player->knockUp.x;
    player->playerPos.y = player->playerPos.y + player->knockUp.y;
  }
  else if (screen->gameScreen == GAMEPLAY && player->collisionState == HITTING && player->playerMoveState == MOVELEFT)
  {
    player->playerPos.x = player->playerPos.x + player->knockRight.x;
    player->playerPos.y = player->playerPos.y + player->knockRight.y;
  }
  else if (screen->gameScreen == GAMEPLAY && player->collisionState == HITTING && player->playerMoveState == MOVERIGHT)
  {
    player->playerPos.x = player->playerPos.x + player->knockLeft.x;
    player->playerPos.y = player->playerPos.y + player->knockLeft.y;
  }
  else if (screen->gameScreen == GAMEPLAY && player->collisionState == HITTING && player->playerMoveState == MOVEUPLEFT)
  {
    player->playerPos.x = player->playerPos.x + player->knockDownRight.x;
    player->playerPos.y = player->playerPos.y + player->knockDownRight.y;
  }
  else if (screen->gameScreen == GAMEPLAY && player->collisionState == HITTING && player->playerMoveState == MOVEUPRIGHT)
  {
    player->playerPos.x = player->playerPos.x + player->knockDownLeft.x;
    player->playerPos.y = player->playerPos.y + player->knockDownLeft.y;
  }
  else if (screen->gameScreen == GAMEPLAY && player->collisionState == HITTING && player->playerMoveState == MOVEDOWNLEFT)
  {
    player->playerPos.x = player->playerPos.x + player->knockUpRight.x;
    player->playerPos.y = player->playerPos.y + player->knockUpRight.y;
  }
  else if (screen->gameScreen == GAMEPLAY && player->collisionState == HITTING && player->playerMoveState == MOVEDOWNRIGHT)
  {
    player->playerPos.x = player->playerPos.x + player->knockUpLeft.x;
    player->playerPos.y = player->playerPos.y + player->knockUpLeft.y;
  };
}
