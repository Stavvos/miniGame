#include "types.h"

void movingForward(struct Player* player, struct Screen* screen, struct Game* game){  
  
  if(screen->gameScreen == GAMEPLAY && player->playerPos.y > screen->topBoundary)
  {
    player->playerPos.x += player->moveUp.x * game->deltaTime * player->speed;
    player->playerPos.y += player->moveUp.y * game->deltaTime * player->speed; 
  };
}

void movingBackward(struct Player* player, struct Screen* screen, struct Game* game){
  
  if(screen->gameScreen == GAMEPLAY && player->playerPos.y < screen->bottomBoundary)
  {
    player->playerPos.x += player->moveDown.x * game->deltaTime * player->speed;
    player->playerPos.y += player->moveDown.y * game->deltaTime * player->speed;
  };
}

void movingLeft(struct Player* player, struct Screen* screen, struct Game* game){
  
  if(screen->gameScreen == GAMEPLAY && player->playerPos.x > screen->leftBoundary)
  {
    player->playerPos.x += player->moveLeft.x * game->deltaTime * player->speed; 
    player->playerPos.y += player->moveLeft.y * game->deltaTime * player->speed;   
  };
}

void movingRight(struct Player* player, struct Screen* screen, struct Game* game){
  
  if(screen->gameScreen == GAMEPLAY && player->playerPos.x < screen->rightBoundary)
  {
    player->playerPos.x += player->moveRight.x * game->deltaTime * player->speed;
    player->playerPos.y += player->moveRight.y * game->deltaTime * player->speed;
  };
}

void movingUpRight(struct Player* player, struct Screen* screen, struct Game* game){
  
  if(screen->gameScreen == GAMEPLAY && player->playerPos.x < screen->rightBoundary
		                    && player->playerPos.y > screen->topBoundary)
  {
    player->playerPos.x += player->moveUpRight.x * game->deltaTime * player->speed;
    player->playerPos.y += player->moveUpRight.y * game->deltaTime * player->speed;  
  };
}

void movingUpLeft(struct Player* player, struct Screen* screen, struct Game* game){
  
  if(screen->gameScreen == GAMEPLAY && player->playerPos.x > screen->leftBoundary
		                    && player->playerPos.y > screen->topBoundary)
  {
    player->playerPos.x += player->moveUpLeft.x * game->deltaTime * player->speed;
    player->playerPos.y += player->moveUpLeft.y * game->deltaTime * player->speed;  
  };
}

void movingDownRight(struct Player* player, struct Screen* screen, struct Game* game){

  if(screen->gameScreen == GAMEPLAY && player->playerPos.x < screen->rightBoundary
                                    && player->playerPos.y < screen->bottomBoundary)
  {
    player->playerPos.x += player->moveDownRight.x * game->deltaTime * player->speed;
    player->playerPos.y += player->moveDownRight.y * game->deltaTime * player->speed;
  };
}

void movingDownLeft(struct Player* player, struct Screen* screen, struct Game* game){

  if(screen->gameScreen == GAMEPLAY && player->playerPos.y < screen->bottomBoundary
		                    && player->playerPos.x > screen->leftBoundary)
  {
    player->playerPos.x += player->moveDownLeft.x * game->deltaTime * player->speed;
    player->playerPos.y += player->moveDownLeft.y * game->deltaTime * player->speed;
  };
}

void updatePlayerHitBox(struct Player* player)
{
  
  player->playerHitBox.x = player->playerPos.x;
  player->playerHitBox.y = player->playerPos.y;
}

void playerMovementHandler(struct Player* player, struct Screen* screen, struct Game* game) {

//Update player move state
switch(player->playerMoveState)
 {
  case NOMOVE:
  {

  } break;

  case MOVEFORWARD:
  {
    movingForward(player, screen, game);
  } break;

  case MOVEBACKWARD:
  {
    movingBackward(player, screen, game);
  } break;

  case MOVELEFT:
  {
    movingLeft(player, screen, game); 
  } break;

  case MOVERIGHT:
  {
    movingRight(player, screen, game); 
  } break;

  case MOVEUPRIGHT:
  {
    movingUpRight(player, screen, game);
  } break;

  case MOVEUPLEFT:
  {
    movingUpLeft(player, screen, game);
  } break;

  case MOVEDOWNLEFT:
  {
    movingDownLeft(player, screen, game);
  } break;
  
  case MOVEDOWNRIGHT:
  {
    movingDownRight(player, screen, game);
  } break;

  default: break;

 }

}
