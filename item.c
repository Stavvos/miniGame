#include "types.h"

void resetLifePickupLocation(struct LifePickup* lifePickup, struct Game* game)
{
  if (game->resetItemLocation == true)
  {
    lifePickup->position = lifePickup->defaultLocation;
    lifePickup->hitBox.x = lifePickup->defaultLocation.x;
    lifePickup->hitBox.y = lifePickup->defaultLocation.y;
    game->resetItemLocation = false;
    lifePickup->active = false;
  }
}

void moveItem(struct LifePickup* lifePickup, struct Screen* screen, struct Game* game)
{
  if (lifePickup->active == true && screen->gameScreen == GAMEPLAY)
  {
    lifePickup->position.y += lifePickup->speed * game->deltaTime;
    lifePickup->hitBox.y += lifePickup->speed * game->deltaTime;
  }
}

void checkItemOffScreen(struct LifePickup* lifePickup, double screenHeight, struct Game* game)
{
  if (lifePickup->position.y > screenHeight)
  {
    game->resetItemLocation = true;
  } 
}
