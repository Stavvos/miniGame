#include "types.h"

void resetLifePickupLocation(struct LifePickup* lifePickup, struct Game* game)
{
  if(game->resetItemLocation == true)
  {
    printf("\n\nding ding ding\n\n");
    lifePickup->position.x = 40;
    lifePickup->position.y = 50;
    lifePickup->hitBox.x = 40;
    lifePickup->hitBox.y = 50;
    game->resetItemLocation = false;
  }

  //printf("\n%f\n", lifePickup->position.x);
  //printf("\n%f\n", lifePickup->position.y);
  //printf("\n%f\n", lifePickup->hitBox.x);
  //printf("\n%f\n", lifePickup->hitBox.y);
  //printf("\n%d\n", game->resetItemLocation);
}
