#include "types.h"
#include "math.h"

void moveAsteroid(struct SmallAsteroid* smallAsteroid, struct Player* player, struct Screen* screen)
{
  
  if (screen->gameScreen == GAMEPLAY)
  {
    smallAsteroid->direction.x = player->playerPos.x - smallAsteroid->position.x;
    smallAsteroid->direction.y = player->playerPos.y - smallAsteroid->position.y;

    smallAsteroid->hypotenuse = sqrt(smallAsteroid->direction.x * smallAsteroid->direction.x + 
		                     smallAsteroid->direction.y * smallAsteroid->direction.y);
    
    smallAsteroid->direction.x /= smallAsteroid->hypotenuse;
    smallAsteroid->direction.y /= smallAsteroid->hypotenuse;

    smallAsteroid->position.x += smallAsteroid->direction.x;
    smallAsteroid->position.y += smallAsteroid->direction.y;

    smallAsteroid->hitBox.x = smallAsteroid->position.x;
    smallAsteroid->hitBox.y = smallAsteroid->position.y;
  }
}
