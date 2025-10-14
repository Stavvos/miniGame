#include "types.h"

void deallocateSoundFX(Sound sounds[], struct Game* game)
{
  for(int i = 0; i < game->MAXBULLETS; i++)
  {
    UnloadSound(sounds[i]);
  }
}

