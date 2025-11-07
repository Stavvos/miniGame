#include "raylib.h"

void deallocateShootingSoundFX(Sound sounds[], struct Game* game)
{
  for(int i = 0; i < game->MAXBULLETS; i++)
  {
    UnloadSound(sounds[i]);
  }
}

void deallocateExplosionSoundFX(struct Explosion explosions[])
{
  for(int i = 0; i < 10; i++)
  {
    UnloadSound(explosions[i].sound);
  }
}

