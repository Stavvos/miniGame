#include "types.h"
#include "math.h"

void moveAsteroids(struct Player* player, struct Screen* screen, struct Game* game, struct Asteroid* head)
{
    
  if(screen->gameScreen == GAMEPLAY)
  {
    struct Asteroid* current = head;

    while(current != NULL)
    {
      current->direction.x = player->playerPos.x - current->position.x;
      current->direction.y = player->playerPos.y - current->position.y;

      current->hypotenuse = sqrt(current->direction.x * current->direction.x + current->direction.y * current->direction.y);
    
      current->direction.x /= current->hypotenuse;
      current->direction.y /= current->hypotenuse;
     
      //minimise the asteroids stacking ontop of one another 
      float randomOffsetX = ((rand() % 100) - 50) * 0.01;  
      float randomOffsetY = ((rand() % 100)- 50) * 0.01;  
      
      current->position.x += (randomOffsetX + current->direction.x) * game->deltaTime * current->speed;
      current->position.y += (randomOffsetY + current->direction.y) * game->deltaTime * current->speed;

      current->hitBox.x = current->position.x;
      current->hitBox.y = current->position.y;

      current = current->next;
    }
  }

}
