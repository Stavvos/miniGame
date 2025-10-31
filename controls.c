#include "raylib.h"
#include "types.h"

void controlsHandler(struct Player* player){

   if(IsKeyDown(KEY_W))
   {
      player->playerMoveState = MOVEFORWARD;
   }
   
   if(IsKeyDown(KEY_S)) 
   {
      player->playerMoveState = MOVEBACKWARD;
   }
   
   if(IsKeyDown(KEY_D)) 
   {
      player->playerMoveState = MOVERIGHT;
   }
   
   if(IsKeyDown(KEY_A)) 
   {
      player->playerMoveState = MOVELEFT;
   }

   if(IsKeyDown(KEY_W) && IsKeyDown(KEY_D)) 
   {
      player->playerMoveState = MOVEUPRIGHT;
   }
   
   if(IsKeyDown(KEY_W) && IsKeyDown(KEY_A)) 
   {
      player->playerMoveState = MOVEUPLEFT;
   }
   
   if(IsKeyDown(KEY_S) && IsKeyDown(KEY_D)) 
   {
      player->playerMoveState = MOVEDOWNRIGHT;
   }
   
   if(IsKeyDown(KEY_S) && IsKeyDown(KEY_A)) 
   {
      player->playerMoveState = MOVEDOWNLEFT;
   }
   
   //shoot
   if(IsKeyPressed(KEY_SPACE))
   {
     player->playerShootState = SHOOTING;
   }
   
   //not moving 
   if (IsKeyUp(KEY_S) && IsKeyUp(KEY_W) && IsKeyUp(KEY_A) && IsKeyUp(KEY_D))
   {
     player->playerMoveState = NOMOVE;
   }
     
}

