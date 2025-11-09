#include "types.h"

void resetLifePickupLocation(struct LifePickup* lifePickup, struct Game* game)
{
  if(game->resetItemLocation == true)
  {
    lifePickup->position.x = 40;
    lifePickup->position.y = 50;
    lifePickup->hitBox.x = 40;
    lifePickup->hitBox.y = 50;
    game->resetItemLocation = false;
    lifePickup->active = false;
  }
}

void moveItem(struct LifePickup* lifePickup, struct Screen* screen)
{
  if(lifePickup->active == true && screen->gameScreen == GAMEPLAY)
  {
    lifePickup->position.y += lifePickup->speed;
    lifePickup->hitBox.y += lifePickup->speed;
  }
}
