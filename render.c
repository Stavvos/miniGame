#include "raylib.h"
#include "types.h"

void drawMenuScreen()
{
  DrawText("GAME PAUSED", 200, 200, 20, WHITE);
  DrawText("Press ENTER to start the game.", 400, 400, 14, WHITE);
  DrawText("Press ESC to quit the game.", 400, 450, 14, WHITE);
}

void drawPlayer(struct Player* player)
{

  DrawTexture(player->playerTexture, player->playerPos.x, player->playerPos.y, WHITE);
  DrawRectangleLines(player->playerHitBox.x, 
		     player->playerHitBox.y, 
	             player->playerHitBox.width, 
	             player->playerHitBox.height, 
		     BLACK);
}

void drawAsteroids(struct Asteroid* head)
{
  struct Asteroid* current = head;
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
}

void drawBullets(struct Bullet bullets[])
{
  for(int i = 0; i < 10; i++)
  {
    if(bullets[i].active)
    {
      DrawRectangle(bullets[i].hitBox.x, bullets[i].hitBox.y, bullets[i].hitBox.width, bullets[i].hitBox.height, BLACK);
    }
  }
}

void drawHealthBar(struct HealthBar* healthBar, struct Player* player)
{
  DrawRectangle(healthBar->background.x,
                healthBar->background.y,
                healthBar->background.width,
                healthBar->background.height, 
		BLACK);

  for (int i = 0; i < player->playerHealth; i++)
  {

    DrawRectangle(healthBar->forground[i].x,
                  healthBar->forground[i].y,
                  healthBar->forground[i].width,
                  healthBar->forground[i].height,
                  GREEN);
  }

}

void drawPlayerLives(struct Player* player)
{
  DrawText(TextFormat("Lives %d", player->playerLives), 40, 20, 20, GREEN); 
}

void drawPlayerScore(struct Player* player)
{
  DrawText(TextFormat("Score %d", player->score), 180, 20, 20, GREEN); 
}

void drawGameOverScreen()
{
  DrawText("GAME OVER", 200, 200, 20, WHITE);
  DrawText("Press ENTER to restart the game.", 400, 400, 14, WHITE);
  DrawText("Press ESC to quit the game.", 400, 450, 14, WHITE);
}

void drawLevelWinScreen()
{
  DrawText("LEVEL COMPLETED", 200, 200, 20, WHITE);
  DrawText("Press ENTER to proceed to next level.", 400, 400, 14, WHITE);
  DrawText("Press ESC to quit the game.", 400, 450, 14, WHITE);
}

void drawGameWinScreen()
{
  DrawText("CONGRATULATIONS YOU COMPLETED THE GAME!", 200, 200, 20, WHITE);
  DrawText("Press ENTER to restart the game.", 400, 400, 14, WHITE);
  DrawText("Press ESC to quit the game.", 400, 450, 14, WHITE);
}

void render(struct Screen* screen, struct Player* player, struct Game* game, struct Asteroid* head, struct Bullet bullets[], struct HealthBar* healthBar)
{

  switch(screen->gameScreen)
  {
    case MENU:
    {
      ClearBackground(BLACK);
      drawMenuScreen();
    } break;

    case GAMEPLAY:
    {
      ClearBackground(RAYWHITE);
      drawPlayer(player);
      drawAsteroids(head); 
      drawBullets(bullets);
      drawHealthBar(healthBar, player);
      drawPlayerLives(player);
      drawPlayerScore(player); 
    } break;
    
    case GAMEOVER:
    {
      ClearBackground(BLACK);
      drawGameOverScreen();
    } break;

    case WONLEVEL:
    {
      ClearBackground(BLACK);
      drawLevelWinScreen();
    } break;

    case WONGAME:
    {
      ClearBackground(BLACK);
      drawGameWinScreen();
    } break;

      default: break;
  }
}
