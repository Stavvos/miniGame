#include "types.h"
#include "math.h"

void moveAsteroids(struct SmallAsteroid smallAsteroids[], struct MediumAsteroid mediumAsteroids[], struct LargeAsteroid largeAsteroids[], struct Player* player, struct Screen* screen, struct Game* game)
{
    
  for (int i = 0; i < game->SMALLASTEROIDCOUNT; i++)
  {
    if (screen->gameScreen == GAMEPLAY && smallAsteroids[i].collisionState == NOTHITTING)
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
  
  for (int i = 0; i < game->MEDIUMASTEROIDCOUNT; i++)
  {
    if (screen->gameScreen == GAMEPLAY)
      {
        mediumAsteroids[i].direction.x = player->playerPos.x - mediumAsteroids[i].position.x;
        mediumAsteroids[i].direction.y = player->playerPos.y - mediumAsteroids[i].position.y;

        mediumAsteroids[i].hypotenuse = sqrt(mediumAsteroids[i].direction.x * mediumAsteroids[i].direction.x + 
		                             mediumAsteroids[i].direction.y * mediumAsteroids[i].direction.y);
    
        mediumAsteroids[i].direction.x /= mediumAsteroids[i].hypotenuse;
        mediumAsteroids[i].direction.y /= mediumAsteroids[i].hypotenuse;

        mediumAsteroids[i].position.x += mediumAsteroids[i].direction.x;
        mediumAsteroids[i].position.y += mediumAsteroids[i].direction.y;

        mediumAsteroids[i].hitBox.x = mediumAsteroids[i].position.x;
        mediumAsteroids[i].hitBox.y = mediumAsteroids[i].position.y;
      }
  }

  for (int i = 0; i < game->LARGEASTEROIDCOUNT; i++)
  {
    if (screen->gameScreen == GAMEPLAY)
      {
        largeAsteroids[i].direction.x = player->playerPos.x - largeAsteroids[i].position.x;
        largeAsteroids[i].direction.y = player->playerPos.y - largeAsteroids[i].position.y;

        largeAsteroids[i].hypotenuse = sqrt(largeAsteroids[i].direction.x * largeAsteroids[i].direction.x + 
		                            largeAsteroids[i].direction.y * largeAsteroids[i].direction.y);
    
        largeAsteroids[i].direction.x /= largeAsteroids[i].hypotenuse;
        largeAsteroids[i].direction.y /= largeAsteroids[i].hypotenuse;

        largeAsteroids[i].position.x += largeAsteroids[i].direction.x;
        largeAsteroids[i].position.y += largeAsteroids[i].direction.y;

        largeAsteroids[i].hitBox.x = largeAsteroids[i].position.x;
        largeAsteroids[i].hitBox.y = largeAsteroids[i].position.y;
      }
  }
}
