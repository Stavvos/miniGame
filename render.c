#include "raylib.h"
#include "types.h"

void render(struct Screen* screen, struct Player* player, struct Game* game, asteroid* head, struct Bullet bullets[])
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
      
      
      asteroid* current = head;
      while(current != NULL)
      {
        DrawTexture(current->texture, current->position.x, current->position.y, WHITE);
        DrawRectangleLines(current->position.x,
		           current->position.y, 
			   current->hitBox.width, 
			   current->hitBox.height, 
      			   BLACK);

	current = current->next;
      }

      for(int i = 0; i < 10; i++)
      {
        if(bullets[i].active)
	{
	  DrawRectangle(bullets[i].hitBox.x, bullets[i].hitBox.y, bullets[i].hitBox.width, bullets[i].hitBox.height, BLACK);
	}
      }

    } break;

      default: break;
  }
}
