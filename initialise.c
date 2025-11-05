#include "raylib.h"
#include "types.h"

void initBullets(struct Bullet bullets[], struct Game* game)
{
  for(int i = 0; i < game->MAXBULLETS; i++)
  {
    bullets[i].active = false;
    bullets[i].hitBox.width = 5;
    bullets[i].hitBox.height = 5;
    bullets[i].speed = 5;
  }
}

void initGame(struct Game* game)
{
  game->gameState = PLAYING;
  game->MAXBULLETS = 15;
  game->level = 0;
  game->MAXLEVEL = 2;
  game->resetItemLocation = false;
}

void initAudio(struct Audio* audio, struct Game* game, Sound sounds[])
{
  
  audio->activeSoundFX = 0;

  for(int i = 0; i < game->MAXBULLETS; i++)
  {
    sounds[i] = LoadSound("assets/sound/fart.mp3");
  }

}

void initPlayer(struct Player* player)
{
  player->moveUp = (Vector2){0, -1};
  player->moveDown = (Vector2){0, 1};
  player->moveLeft = (Vector2){-1, 0};
  player->moveRight = (Vector2){1, 0};

  //these values are set to 0.707 as an approximate value for handling diagonal movement.
  //the key to these values being useful lies within the pythagoras theorum a^2 + b^2 = c^2
  //think of the hypotenuse of a right sided triangle
  //
  //for example: if you add the up vector (1 movement up) and the left vector(1 movement left) for 
  //up left movement the player's speed is too fast by approximately 40%. the value 0.707 handles this well. 
  player->moveUpRight = (Vector2){0.707, -0.707};
  player->moveUpLeft = (Vector2){-0.707, -0.707};
  player->moveDownRight = (Vector2){0.707, 0.707};
  player->moveDownLeft = (Vector2){-0.707, 0.707};
  player->playerPos = (Vector2){300.f, 280.f};
  player->playerHitBox.x = player->playerPos.x;
  player->playerHitBox.y = player->playerPos.y;
  player->playerHitBox.width = 8;
  player->playerHitBox.height = 9;
  player->playerTexture = LoadTexture("assets/sprite/player/ship.png");
  player->collisionState = NOTHITTING;
  player->playerHealth = PLAYERHEALTH;
  player->playerLives = PLAYERLIVES;
  player->score = 0;
  player->invulnFrames = 0;
  player->invulnRenderPlayer = true;
}

void initHealthBar(struct HealthBar* healthBar)
{
  healthBar->background.x = 280;
  healthBar->background.y = 25;
  healthBar->background.width = 50; 
  healthBar->background.height = 10;
        
  int offSet = 1; 
  for (int i = 0; i < PLAYERHEALTH; i++)
  {
    healthBar->forground[i].x = healthBar->background.x + offSet;
    healthBar->forground[i].y = healthBar->background.y + 1;
    healthBar->forground[i].width = healthBar->background.width - 42;
    healthBar->forground[i].height = healthBar->background.height - 2;
    offSet += healthBar->background.width / PLAYERHEALTH;
  }
}

void initScreen(struct Screen* screen)
{
  screen->gameScreen = MENU;
  screen->topBoundary = 0;
}
