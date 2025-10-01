#include "types.h"
#include "math.h"

void moveAsteroid(struct SmallAsteroid* smallAsteroid, struct SmallAsteroid smallAsteroids[], struct Player* player, struct Screen* screen)
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
  
  for (int i = 0; i < 4; i++)
  {
    if (screen->gameScreen == GAMEPLAY)
      {
        smallAsteroids[i].direction.x = player->playerPos.x - smallAsteroids[i].position.x;
        smallAsteroids[i].direction.y = player->playerPos.y - smallAsteroids[i].position.y;

        smallAsteroids[i].hypotenuse = sqrt(smallAsteroids[i].direction.x * smallAsteroids[i].direction.x + 
		                            smallAsteroids[i].direction.y * smallAsteroids[i].direction.y);
    
        smallAsteroids[i].direction.x /= smallAsteroids[i].hypotenuse;
        smallAsteroids[i].direction.y /= smallAsteroids[i].hypotenuse;

        smallAsteroids[i].position.x += smallAsteroids[i].direction.x;
        smallAsteroids[i].position.y += smallAsteroids[i].direction.y;

        smallAsteroids[i].hitBox.x = smallAsteroids[i].position.x;
        smallAsteroids[i].hitBox.y = smallAsteroids[i].position.y;
      }
  }

}
