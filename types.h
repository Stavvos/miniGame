#ifndef TYPES_H
#define TYPES_H

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

typedef enum GameScreen 
{
  MENU, 
  GAMEPLAY
} GameScreen;

typedef enum GameState 
{
  PLAYING, 
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
  int MAXBULLETS;
};

struct Screen 
{
  GameScreen gameScreen; 
};

struct Bullet
{
  Rectangle hitBox;
  bool active;
  int speed;
}; 

struct Audio
{
  int activeSoundFX;
};

struct Player 
{
  Texture2D playerTexture;
  Rectangle playerHitBox;
  PlayerMoveState playerMoveState;
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
};

typedef struct Asteroid
{
  Rectangle hitBox;
  Texture2D texture;
  Vector2 position;
  Vector2 direction;
  float hypotenuse;
  CollisionState collisionState;
  struct Asteroid* next;
} asteroid;

#endif
