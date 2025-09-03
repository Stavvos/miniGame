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

struct Player 
{
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

#endif



