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
