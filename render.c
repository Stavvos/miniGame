#include "raylib.h"
#include "types.h"


void render(struct Screen* screen, struct Player* player, struct Game* game, struct SmallAsteroid smallAsteroids[], struct MediumAsteroid mediumAsteroids[], struct LargeAsteroid largeAsteroids[])
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

      for(int i = 0; i < game->SMALLASTEROIDCOUNT; i++)
      {
        DrawTexture(smallAsteroids[i].texture, smallAsteroids[i].position.x, smallAsteroids[i].position.y, WHITE);
        DrawRectangleLines(smallAsteroids[i].position.x,
		           smallAsteroids[i].position.y, 
			   smallAsteroids[i].hitBox.width, 
			   smallAsteroids[i].hitBox.height, 
			   BLACK);
      } 
      
      for (int i = 0; i < game->MEDIUMASTEROIDCOUNT; i++)
      {
        DrawTexture(mediumAsteroids[i].texture, mediumAsteroids[i].position.x, mediumAsteroids[i].position.y, WHITE);
        DrawRectangleLines(mediumAsteroids[i].position.x,
		           mediumAsteroids[i].position.y, 
			   mediumAsteroids[i].hitBox.width, 
			   mediumAsteroids[i].hitBox.height, 
			   BLACK);
      }
      
      for (int i = 0; i < game->LARGEASTEROIDCOUNT; i++)
      {
        DrawTexture(largeAsteroids[i].texture, largeAsteroids[i].position.x, largeAsteroids[i].position.y, WHITE);
        DrawRectangleLines(largeAsteroids[i].position.x,
		           largeAsteroids[i].position.y, 
			   largeAsteroids[i].hitBox.width, 
			   largeAsteroids[i].hitBox.height, 
			   BLACK);
      }
      
    } break;

      default: break;
  }
}
