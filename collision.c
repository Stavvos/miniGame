#include "raylib.h"
#include "types.h"

void moveItemToHitAsteroid(struct Asteroid* current, struct LifePickup* lifePickup, struct Game* game)
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

void activateExplosionSoundFX(struct Explosion explosions[], struct Asteroid* current)
{
  for (int i = 0; i < 10; i++)
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

void asteroidPlayerCollisionHandler(struct Player* player, struct Game* game, struct Asteroid** head)
{
 
  struct Asteroid* current = *head;
  struct Asteroid* previous = NULL;

  while(current != NULL)
  {
    if (CheckCollisionRecs(player->playerHitBox, current->hitBox) && player->invulnFrames == 0)
    {
      player->collisionState = HITTING;
      
      if (player->playerHealth > 0)
      {
        player->playerHealth--;      
      }
      
      struct Asteroid* next = current->next;
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

void bulletHitAsteroid(struct Asteroid** head, struct Bullet bullets[], struct Game* game, struct Player* player, struct LifePickup* lifePickup, struct Explosion explosions[])
{
 
  for(int i = 0; i < game->MAXBULLETS; i++)
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
          activateExplosionSoundFX(explosions, current); 
          moveItemToHitAsteroid(current, lifePickup, game);
          deleteAsteroid(current, previous, head);
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
    printf("\n\nHitting\n\n");
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
