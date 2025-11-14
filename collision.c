#include "raylib.h"
#include "types.h"

void moveItemToHitAsteroid(struct Asteroid* current, struct LifePickup* lifePickup)
{
  if(current->hasItem == true)
  {
    lifePickup->position.x = current->position.x;
    lifePickup->position.y = current->position.y;
    lifePickup->hitBox.x = current->position.x;
    lifePickup->hitBox.y = current->position.y;
    lifePickup->active = true;
  }	  
}

void activateExplosionFX(struct Explosion explosions[], struct Asteroid* current)
{
  for (int i = 0; i < MAXEXPLOSIONS; i++)
  {
    if(explosions[i].active == false)
    {
      explosions[i].active = true;
      explosions[i].playSound = true;
      explosions[i].position = current->position;
      break; //exit loop 
    }
  }
}

void activateCollisionSoundFX(struct CollisionSound collisionSounds[])
{
  for (int i = 0; i < COLLISIONSOUNDS; i++)
  {
    if (collisionSounds[i].active == false)
    {
      collisionSounds[i].active = true;
      break;
    }
  }
}

void asteroidPlayerCollisionHandler(struct Player* player, struct Asteroid** head, struct CollisionSound collisionSounds[])
{
 
  struct Asteroid* current = *head;
  struct Asteroid* previous = NULL;

  while(current != NULL)
  {
    if (CheckCollisionRecs(player->playerHitBox, current->hitBox) && player->invulnFrames == 0)
    {
      struct Asteroid* next = current->next;
      player->hitTally += current->damage;
      activateCollisionSoundFX(collisionSounds);
      deleteAsteroid(current, previous, head);
      current = next;
    }
    else //no collision found, move onto the node
    {
      previous = current;
      current = current->next;
    }
  }

}

void bulletHitAsteroid(struct Asteroid** head, struct Bullet bullets[], struct Player* player, struct LifePickup* lifePickup, struct Explosion explosions[])
{
 
  for(int i = 0; i < MAXBULLETS; i++)
  {
    struct Asteroid* current = *head;
    struct Asteroid* previous = NULL;
 
    if(bullets[i].active)
    {
      while(current != NULL)
      {
        if (CheckCollisionRecs(bullets[i].hitBox, current->hitBox))
        {
          struct Asteroid* next = current->next;
          player->score += current->points;
	  current->health--;
	  current->currentTexture++;
	  bullets[i].active = false;

	  if(current->health == 0)
	  {
            deleteAsteroid(current, previous, head);
            activateExplosionFX(explosions, current); 
            moveItemToHitAsteroid(current, lifePickup);
	  }

	  current = next;
        }
        else //no collision found, move onto the next node
        {
          previous = current;
          current = current->next;
        }
      }
    }
  }
}

void itemCollisionHandler(struct LifePickup* lifePickup, struct Player* player, struct Game* game)
{
  if(CheckCollisionRecs(lifePickup->hitBox, player->playerHitBox) && lifePickup->active == true)
  {
    if(player->playerHealth == PLAYERHEALTH)
    {
      player->playerLives++;
      lifePickup->active = false;
      game->resetItemLocation = true;

    }
    else
    {
      player->playerHealth = PLAYERHEALTH;
      lifePickup->active = false;
      game->resetItemLocation = true;
    }
  }
}

void collisionCleanup(struct Player* player)
{
  player->collisionState = NOTHITTING;
}
