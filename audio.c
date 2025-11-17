#include "types.h"

void playExplosionSound(struct Explosion explosions[])
{
  for (int i = 0; i < 10; i++)
  {
    if(explosions[i].playSound == true)
    {
      PlaySound(explosions[i].sound); 
      explosions[i].playSound = false;
    }
  }
}

void playBulletSound(struct Bullet bullets[])
{
  for (int i = 0; i < 15; i++)
  {
    if(bullets[i].playSound == true)
    {
      PlaySound(bullets[i].sound); 
      bullets[i].playSound = false;
    }
  }
}

void playCollisionSound(struct CollisionSound collisionSounds[])
{
  for (int i = 0; i < COLLISIONSOUNDS; i++)
  {
    if(collisionSounds[i].active == true)
    {
      PlaySound(collisionSounds[i].sound);
      collisionSounds[i].active = false;
    }
  }
}

void playItemPickupSound(struct LifePickup* lifePickup)
{
  if (lifePickup->collision == true)
  {
    PlaySound(lifePickup->sound);
    lifePickup->collision = false;
  }
}
