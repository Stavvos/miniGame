#include "types.h"
#include "math.h"
#include "raymath.h"

Vector2 separateAsteroids(struct Asteroid* head, struct Asteroid* asteroid)
{
  Vector2 result = {0, 0};
  float distanceLimit = 20.0;
  
  struct Asteroid* current = head;

  while (current != NULL)
  {
    if (current != asteroid)
    {
      float distance = Vector2Distance(asteroid->position, current->position);
      
      if (distance < distanceLimit)
      {
        result.x -= current->position.x - asteroid->position.x; 
        result.y -= current->position.y - asteroid->position.y; 
      }
    }
    current = current->next;
  }
  return result;
}

void moveAsteroids(struct Player* player, struct Screen* screen, struct Game* game, struct Asteroid* head)
{
    
  if(screen->gameScreen == GAMEPLAY)
  {
    struct Asteroid* current = head;

    while(current != NULL)
    {
      Vector2 adjustment = separateAsteroids(head, current);
      adjustment.x *= 0.1;
      adjustment.y *= 0.1;

      current->direction.x = player->playerPos.x - current->position.x;
      current->direction.y = player->playerPos.y - current->position.y;

      current->hypotenuse = sqrt(current->direction.x * current->direction.x + current->direction.y * current->direction.y);
    
      current->direction.x /= current->hypotenuse;
      current->direction.y /= current->hypotenuse;
      
      current->position.x += (adjustment.x + current->direction.x) * game->deltaTime * current->speed;
      current->position.y += (adjustment.y + current->direction.y) * game->deltaTime * current->speed;

      current->hitBox.x = current->position.x;
      current->hitBox.y = current->position.y;

      current = current->next;
    }
  }
}
