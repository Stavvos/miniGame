#include "types.h"

void movingForward(struct Player* player, struct Screen* screen){  
  
  if(screen->gameScreen == GAMEPLAY)
  {
    player->playerPos.x = player->playerPos.x + player->moveUp.x;
    player->playerPos.y = player->playerPos.y + player->moveUp.y; 
  };
}

void movingBackward(struct Player* player, struct Screen* screen){
  
  if(screen->gameScreen == GAMEPLAY)
  {
    player->playerPos.x = player->playerPos.x + player->moveDown.x;
    player->playerPos.y = player->playerPos.y + player->moveDown.y;
  };
}

void movingLeft(struct Player* player, struct Screen* screen){
  
  if(screen->gameScreen == GAMEPLAY)
  {
    player->playerPos.x = player->playerPos.x + player->moveLeft.x; 
    player->playerPos.y = player->playerPos.y + player->moveLeft.y;   
  };
}

void movingRight(struct Player* player, struct Screen* screen){
  
  if(screen->gameScreen == GAMEPLAY)
  {
    player->playerPos.x = player->playerPos.x + player->moveRight.x;
    player->playerPos.y = player->playerPos.y + player->moveRight.y;
  };
}

void movingUpRight(struct Player* player, struct Screen* screen){
  
  if(screen->gameScreen == GAMEPLAY)
  {
    player->playerPos.x = player->playerPos.x + player->moveUpRight.x;
    player->playerPos.y = player->playerPos.y + player->moveUpRight.y;  
  };
}

void movingUpLeft(struct Player* player, struct Screen* screen){
  
  if(screen->gameScreen == GAMEPLAY)
  {
    player->playerPos.x = player->playerPos.x + player->moveUpLeft.x;
    player->playerPos.y = player->playerPos.y + player->moveUpLeft.y;  
  };
}

void movingDownRight(struct Player* player, struct Screen* screen){

  if(screen->gameScreen == GAMEPLAY)
  {
    player->playerPos.x = player->playerPos.x + player->moveDownRight.x;
    player->playerPos.y = player->playerPos.y + player->moveDownRight.y;
  };
}

void movingDownLeft(struct Player* player, struct Screen* screen){

  if(screen->gameScreen == GAMEPLAY)
  {
    player->playerPos.x = player->playerPos.x + player->moveDownLeft.x;
    player->playerPos.y = player->playerPos.y + player->moveDownLeft.y;
  };
}

void updatePlayerHitBox(struct Player* player)
{
  
  player->playerHitBox.x = player->playerPos.x;
  player->playerHitBox.y = player->playerPos.y;
}

void playerMovementHandler(struct Player* player, struct Screen* screen) {

//Update player move state
switch(player->playerMoveState)
 {
  case NOMOVE:
  {

  } break;

  case MOVEFORWARD:
  {
    movingForward(player, screen);
  } break;

  case MOVEBACKWARD:
  {
    movingBackward(player, screen);
  } break;

  case MOVELEFT:
  {
    movingLeft(player, screen); 
  } break;

  case MOVERIGHT:
  {
    movingRight(player, screen); 
  } break;

  case MOVEUPRIGHT:
  {
    movingUpRight(player, screen);
  } break;

  case MOVEUPLEFT:
  {
    movingUpLeft(player, screen);
  } break;

  case MOVEDOWNLEFT:
  {
    movingDownLeft(player, screen);
  } break;
  
  case MOVEDOWNRIGHT:
  {
    movingDownRight(player, screen);
  } break;

  default: break;

 }

}
