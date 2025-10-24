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

      current->position.x += current->direction.x;
      current->position.y += current->direction.y;

      current->hitBox.x = current->position.x;
      current->hitBox.y = current->position.y;

      current = current->next;
    }
  }

}
