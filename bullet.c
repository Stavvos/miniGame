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

void spawnBullet(struct Game* game, struct Bullet bullets[], struct Player* player)
{
  for(int i = 0; i < game->MAXBULLETS; i++)
  {
    if(bullets[i].active == false)
    {
      bullets[i].hitBox.x = (player->playerPos.x + player->playerHitBox.x) / 2;
      bullets[i].hitBox.y = player->playerPos.y;
      bullets[i].active = true;
      break;
    }
  }
}

void playBulletSoundFX(struct Sound sounds[], struct Audio* audio, struct Game* game)
{
  PlaySound(sounds[audio->activeSoundFX]);

  audio->activeSoundFX++;

  //wrap back to start of array 
  if(audio->activeSoundFX == game->MAXBULLETS)
  {
    int startIndex = 0;
    audio->activeSoundFX = startIndex;
  }
}

void bulletSpawnHandler(struct Player* player, struct Game* game, struct Bullet bullets[], struct Sound bulletSounds[], struct Audio* audio)
{
  switch(player->playerShootState)
  {
    case SHOOTING:
    {
      spawnBullet(game, bullets, player);
      playBulletSoundFX(bulletSounds, audio, game);
      player->playerShootState = NOTSHOOTING; 
    } break;
    
    case NOTSHOOTING:
    {
    
    } break;

      default: break;
  }
}
