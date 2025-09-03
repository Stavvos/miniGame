#include "types.h"

void noMove(struct Player* player){


}

void movingForward(struct Player* player){
  player->playerPos.x = player->playerPos.x + player->moveUp.x;
  player->playerPos.y = player->playerPos.y + player->moveUp.y; 
}

void movingBackward(struct Player* player){
  player->playerPos.x = player->playerPos.x + player->moveDown.x;
  player->playerPos.y = player->playerPos.y + player->moveDown.y;

}

void movingLeft(struct Player* player){
  player->playerPos.x = player->playerPos.x + player->moveLeft.x; 
  player->playerPos.y = player->playerPos.y + player->moveLeft.y;   
}

void movingRight(struct Player* player){
  player->playerPos.x = player->playerPos.x + player->moveRight.x;
  player->playerPos.y = player->playerPos.y + player->moveRight.y;
}

void movingUpRight(struct Player* player){
  player->playerPos.x = player->playerPos.x + player->moveUpRight.x;
  player->playerPos.y = player->playerPos.y + player->moveUpRight.y;  
}

void movingUpLeft(struct Player* player){
  player->playerPos.x = player->playerPos.x + player->moveUpLeft.x;
  player->playerPos.y = player->playerPos.y + player->moveUpLeft.y;  
}

void movingDownRight(struct Player* player){
  player->playerPos.x = player->playerPos.x + player->moveDownRight.x;
  player->playerPos.y = player->playerPos.y + player->moveDownRight.y;
}

void movingDownLeft(struct Player* player){
  player->playerPos.x = player->playerPos.x + player->moveDownLeft.x;
  player->playerPos.y = player->playerPos.y + player->moveDownLeft.y;
}

void movementHandler( struct Player* player) {

//Update player move state
switch(player -> playerMoveState)
 {
  case NOMOVE:
  {
    noMove(player); 
  } break;

  case MOVEFORWARD:
  {
    movingForward(player);
  } break;

  case MOVEBACKWARD:
  {
    movingBackward(player);
  } break;

  case MOVELEFT:
  {
    movingLeft(player); 
  } break;

  case MOVERIGHT:
  {
    movingRight(player); 
  } break;

  case MOVEUPRIGHT:
  {
    movingUpRight(player);
  } break;

  case MOVEUPLEFT:
  {
    movingUpLeft(player);
  } break;

  case MOVEDOWNLEFT:
  {
    movingDownLeft(player);
  } break;
  
  case MOVEDOWNRIGHT:
  {
    movingDownRight(player);
  } break;

  default: break;

 }

}
