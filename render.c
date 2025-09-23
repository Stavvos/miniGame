#include "raylib.h"
#include "types.h"


void render(struct Screen* screen, struct Player* player, struct SmallAsteroid* smallAsteroid,  struct MediumAsteroid* mediumAsteroid,  struct LargeAsteroid* largeAsteroid)
{

  switch(screen->gameScreen)
  {
    case MENU:
    {
      ClearBackground(BLACK);
      DrawText("Press Enter to start the game.", 400, 400, 14, WHITE);
      DrawText("Press Esc to quit the game.", 400, 450, 14, WHITE);
    } break;

    case GAMEPLAY:
    {
      ClearBackground(RAYWHITE);
      DrawTexture(player->playerTexture, player->playerPos.x, player->playerPos.y, WHITE);
      DrawRectangleLines(player->playerHitBox.x, 
		         player->playerHitBox.y, 
			 player->playerHitBox.width, 
			 player->playerHitBox.height, 
			 BLACK);
      
      DrawTexture(smallAsteroid->texture, smallAsteroid->position.x, smallAsteroid->position.y, WHITE);
      DrawRectangleLines(smallAsteroid->position.x,
		         smallAsteroid->position.y, 
			 smallAsteroid->hitBox.width, 
			 smallAsteroid->hitBox.height, 
			 BLACK);
      
      DrawTexture(mediumAsteroid->texture, mediumAsteroid->position.x, mediumAsteroid->position.y, WHITE);
      DrawRectangleLines(mediumAsteroid->position.x,
		         mediumAsteroid->position.y, 
			 mediumAsteroid->hitBox.width, 
			 mediumAsteroid->hitBox.height, 
			 BLACK);
      
      DrawTexture(largeAsteroid->texture, largeAsteroid->position.x, largeAsteroid->position.y, WHITE);
      DrawRectangleLines(largeAsteroid->position.x,
		         largeAsteroid->position.y, 
			 largeAsteroid->hitBox.width, 
			 largeAsteroid->hitBox.height, 
			 BLACK);

     // DrawTexture(enemy->asteroidMedium, 200.f, 600.f, WHITE);
     // DrawTexture(enemy->asteroidLarge, 920.f, 510.f, WHITE);
    } break;

      default: break;
  }
}
