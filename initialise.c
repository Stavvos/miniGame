#include "raylib.h"
#include "types.h"

void initItem(struct LifePickup* lifePickup)
{
  lifePickup->active = false;
  lifePickup->position = (Vector2){40, 50};
  lifePickup->texture = LoadTexture("assets/sprite/world/pickup.png");
  lifePickup->hitBox.x = lifePickup->position.x;
  lifePickup->hitBox.y = lifePickup->position.y;
  lifePickup->hitBox.width = 16;
  lifePickup->hitBox.height = 16;
  lifePickup->speed = 200;
}

void initBullets(struct Bullet bullets[])
{
  for(int i = 0; i < MAXBULLETS; i++)
  {
    bullets[i].active = false;
    bullets[i].hitBox.width = 5;
    bullets[i].hitBox.height = 5;
    bullets[i].speed = 200;
    bullets[i].sound = LoadSound("assets/sound/fart.mp3"); 
    bullets[i].playSound = false; 
  }
}

void initGame(struct Game* game)
{
  game->gameState = PLAYING;
  game->level = 0;
  game->MAXLEVEL = 2;
  game->resetItemLocation = false;
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
  player->playerShootState = NOTSHOOTING;
  player->score = 0;
  player->invulnFrames = 0;
  player->invulnRenderPlayer = true;
  player->speed = 100.0;
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

void initScreen(struct Screen* screen, struct Player* player)
{
  screen->gameScreen = MENU;
  screen->topBoundary = 0.0;
  screen->leftBoundary = 0.0;
  screen->rightBoundary = GetScreenWidth();
  screen->bottomBoundary = GetScreenHeight();
  screen->rightBoundary -= player->playerHitBox.width; 
  screen->bottomBoundary -= player->playerHitBox.height; 
}

void initExplosions(struct Explosion explosions[])
{
  Texture2D texture1 = LoadTexture("assets/sprite/explosion/explosion1.png");
  Texture2D texture2 = LoadTexture("assets/sprite/explosion/explosion2.png");
  Texture2D texture3 = LoadTexture("assets/sprite/explosion/explosion3.png");
  Texture2D texture4 = LoadTexture("assets/sprite/explosion/explosion4.png");
  Texture2D texture5 = LoadTexture("assets/sprite/explosion/explosion5.png");
  Texture2D texture6 = LoadTexture("assets/sprite/explosion/explosion6.png");
  Texture2D texture7 = LoadTexture("assets/sprite/explosion/explosion7.png");
  Texture2D texture8 = LoadTexture("assets/sprite/explosion/explosion8.png");

  for (int i = 0; i < MAXEXPLOSIONS; i++)
  {
    explosions[i].texture[0] = texture1;
    explosions[i].texture[1] = texture2;
    explosions[i].texture[2] = texture3;
    explosions[i].texture[3] = texture4;
    explosions[i].texture[4] = texture5;
    explosions[i].texture[5] = texture6;
    explosions[i].texture[6] = texture7;
    explosions[i].texture[7] = texture8;
    explosions[i].index = 0;
    explosions[i].active = false;
    explosions[i].playSound = false;
    explosions[i].sound = LoadSound("assets/sound/fart2.mp3");
  }
}
