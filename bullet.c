#include "raylib.h"
#include "types.h"

void deactivateBullets(struct Bullet bullets[], struct Game* game)
{
  for(int i = 0; i < MAXBULLETS; i++)
  {
    bullets[i].active = false;
  }
}

void translateBullet(struct Bullet bullets[], struct Game* game, struct Screen* screen)
{
  if(screen->gameScreen == GAMEPLAY)
  {
    for(int i = 0; i < MAXBULLETS; i++)
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

void spawnBullet(struct Bullet bullets[], struct Player* player)
{
  for(int i = 0; i < MAXBULLETS; i++)
  {
    if(bullets[i].active == false)
    {
      bullets[i].hitBox.x = (player->playerPos.x + player->playerHitBox.x) / 2;
      bullets[i].hitBox.y = player->playerPos.y;
      bullets[i].active = true;
      bullets[i].playSound = true;
      break;
    }
  }
}

void bulletSpawnHandler(struct Player* player, struct Bullet bullets[])
{
  switch(player->playerShootState)
  {
    case SHOOTING:
    {
      spawnBullet(bullets, player);
      player->playerShootState = NOTSHOOTING; 
    } break;
    
    case NOTSHOOTING:
    {
    
    } break;

      default: break;
  }
}
