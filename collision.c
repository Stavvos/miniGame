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
