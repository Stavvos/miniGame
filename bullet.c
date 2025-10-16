#include "raylib.h"
#include "types.h"

void translateBullet(struct Bullet bullets[], struct Game* game, struct Screen* screen)
{
  if(screen->gameScreen == GAMEPLAY)
  {
    for(int i = 0; i < game->MAXBULLETS; i++)
    {
      if (bullets[i].active)
      {
        bullets[i].hitBox.y -= bullets[i].speed;

        if(bullets[i].hitBox.y < 0)
        {
          bullets[i].active = false;
        }
      }
    }
  }  
}
