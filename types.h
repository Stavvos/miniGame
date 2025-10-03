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
  int SMALLASTEROIDCOUNT;
  int MEDIUMASTEROIDCOUNT;
  int LARGEASTEROIDCOUNT;
};

struct Screen 
{
  GameScreen gameScreen; 
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
  Vector2 knockBack;
  Vector2 knockUp;
  Vector2 knockLeft;
  Vector2 knockRight;
  Vector2 knockDownLeft;
  Vector2 knockDownRight;
  Vector2 knockUpLeft;
  Vector2 knockUpRight;
  CollisionState collisionState;
};

struct SmallAsteroid
{
  Rectangle hitBox;
  Texture2D texture;
  Vector2 position;
  Vector2 direction;
  float hypotenuse;
};

struct MediumAsteroid
{
  Rectangle hitBox;
  Texture2D texture;
  Vector2 position;
  Vector2 direction;
  float hypotenuse;
};

struct LargeAsteroid
{
  Rectangle hitBox;
  Texture2D texture;
  Vector2 position;
  Vector2 direction;
  float hypotenuse;
};

#endif



