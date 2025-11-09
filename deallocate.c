#include "raylib.h"

void deallocateShootingSoundFX(struct Bullet bullets[])
{
  for(int i = 0; i < MAXBULLETS; i++)
  {
    UnloadSound(bullets[i].sound);
  }
}

void deallocateExplosionSoundFX(struct Explosion explosions[])
{
  for(int i = 0; i < MAXEXPLOSIONS; i++)
  {
    UnloadSound(explosions[i].sound);
  }
}

