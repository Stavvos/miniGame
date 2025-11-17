#ifndef TYPES_H
#define TYPES_H

#define PLAYERHEALTH 5
#define PLAYERLIVES 3
#define INVULNFRAMES 60
#define MAXEXPLOSIONFRAMES 8 
#define MAXEXPLOSIONS 10
#define MAXBULLETS 15
#define COLLISIONSOUNDS 20
#define MAXTEXTURES 3

#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum PlayerMoveState
{
  MOVEFORWARD, 
  MOVEBACKWARD, 
  MOVELEFT,
  MOVERIGHT, 
  MOVEUPRIGHT,
  MOVEUPLEFT,
  MOVEDOWNRIGHT,
  MOVEDOWNLEFT,
  NOMOVE
} PlayerMoveState;

typedef enum PlayerShootState
{
  SHOOTING,
  NOTSHOOTING
} PlayerShootState;

typedef enum GameScreen 
{
  MENU, 
  CONTROLS,
  GAMEPLAY,
  GAMEOVER,
  WONLEVEL,
  WONGAME
} GameScreen;

typedef enum GameState 
{
  PLAYING,
  RESETLEVEL,
  NEXTLEVEL,
  ENDGAME,
  EXIT
} GameState;

typedef enum CollisionState
{
  NOTHITTING,
  HITTING
} CollisionState;

struct Game
{
  GameState gameState;
  int level;
  int MAXLEVEL;
  bool resetItemLocation;
  float deltaTime; 
};

struct Screen 
{
  GameScreen gameScreen;
  float topBoundary;
  float leftBoundary;
  float bottomBoundary;
  float rightBoundary; 
};

struct Bullet
{
  Rectangle hitBox;
  int speed;
  bool active;
  bool playSound; 
  Sound sound;
}; 

struct Player 
{
  Texture2D playerTexture;
  Rectangle playerHitBox;
  PlayerMoveState playerMoveState;
  PlayerShootState playerShootState;
  Vector2 playerPos;
  Vector2 moveUp;
  Vector2 moveDown;
  Vector2 moveLeft;
  Vector2 moveRight;
  Vector2 moveUpRight;
  Vector2 moveUpLeft;
  Vector2 moveDownRight;
  Vector2 moveDownLeft;
  CollisionState collisionState;
  int playerHealth;
  int playerLives;
  int score;
  int invulnFrames;
  bool invulnRenderPlayer;
  float speed;
  int hitTally;
};

struct LifePickup
{
  Texture2D texture;
  Vector2 position;
  bool active;
  int speed;
  Rectangle hitBox;
  Sound sound;
  bool collision;
  Vector2 defaultLocation;
};

struct Asteroid
{
  Rectangle hitBox;
  Texture2D texture[MAXTEXTURES];
  Vector2 position;
  Vector2 direction;
  float hypotenuse;
  CollisionState collisionState;
  int points;
  bool hasItem;
  int speed;
  int health;
  int damage;
  int noMoveFrames;
  int currentTexture;
  struct Asteroid* next;
};

struct HealthBar
{
  Rectangle background;
  Rectangle forground[PLAYERHEALTH];
}; 

struct Explosion
{
  Texture2D texture[MAXEXPLOSIONFRAMES];
  int index;
  Vector2 position;
  bool active;
  bool playSound;
  Sound sound; 
};

struct CollisionSound
{
  bool active;
  Sound sound;
};

void deleteAsteroid(struct Asteroid* current, struct Asteroid* previous, struct Asteroid** head);
void pushAsteroid(struct Asteroid** head, struct Asteroid* node);
void freeAsteroidList(struct Asteroid* head);
void initialiseLevel(char* fileName, struct Asteroid** head);
void resetExplosions(struct Explosion explosions[]);
struct Asteroid* createAsteroidNode();

#endif
