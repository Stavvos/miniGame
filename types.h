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

struct Game
{
  GameState gameState;
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
};

struct SmallAsteroid
{
  Rectangle hitBox;
  Texture2D texture;
  Vector2 position;
};

struct MediumAsteroid
{
  Rectangle hitBox;
  Texture2D texture;
  Vector2 position;
};

struct LargeAsteroid
{
  Rectangle hitBox;
  Texture2D texture;
  Vector2 position;
};

#endif



