#include "raylib.h"

void deallocateShootingSoundFX(struct Bullet bullets[])
{
  for(int i = 0; i < MAXBULLETS; i++)
  {
    UnloadSound(bullets[i].sound);
  }
}

void deallocateExplosionSoundFX(struct Explosion explosions[], struct BigExplosion bigExplosions[])
{
  for(int i = 0; i < MAXEXPLOSIONS; i++)
  {
    UnloadSound(explosions[i].sound);
  }

  for(int i = 0; i < MAXEXPLOSIONS; i++)
  {
    UnloadSound(bigExplosions[i].sound);
  }
}

void deallocateCollisionSounds(struct CollisionSound collisionSounds[])
{
  for (int i = 0; i < COLLISIONSOUNDS; i++)
  {
   UnloadSound(collisionSounds[i].sound);
  } 
}
