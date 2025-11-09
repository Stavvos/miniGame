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
  if(player->invulnRenderPlayer)
  {
    DrawTexture(player->playerTexture, player->playerPos.x, player->playerPos.y, BLACK);
    DrawRectangleLines(player->playerHitBox.x, 
		       player->playerHitBox.y, 
	               player->playerHitBox.width, 
	               player->playerHitBox.height, 
		       BLACK);
  }
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
  
  DrawText("Health ", 200, 20, 20, GREEN);
}

void drawPlayerLives(struct Player* player)
{
  DrawText(TextFormat("Lives %d", player->playerLives), 80, 20, 20, GREEN); 
}

void drawPlayerScore(struct Player* player)
{
  DrawText(TextFormat("Score %d", player->score), 360, 20, 20, GREEN); 
}

void drawGameOverScreen(struct Player* player)
{
  DrawText("GAME OVER", 200, 200, 20, WHITE);
  DrawText(TextFormat("Score %d", player->score), 400, 400, 20, WHITE); 
  DrawText("Press ENTER to restart the game.", 400, 450, 14, WHITE);
  DrawText("Press ESC to quit the game.", 400, 500, 14, WHITE);
}

void drawLevelWinScreen(struct Player* player)
{
  DrawText("LEVEL COMPLETED", 200, 200, 20, WHITE);
  DrawText(TextFormat("Lives %d", player->playerLives), 400, 300, 20, WHITE); 
  DrawText(TextFormat("Health %d", player->playerHealth), 400, 350, 20, WHITE); 
  DrawText(TextFormat("Score %d", player->score), 400, 400, 20, WHITE); 
  DrawText("Press ENTER to proceed to next level.", 400, 450, 14, WHITE);
  DrawText("Press ESC to quit the game.", 400, 500, 14, WHITE);
}

void drawGameWinScreen(struct Player* player)
{
  DrawText("CONGRATULATIONS YOU COMPLETED THE GAME!", 200, 200, 20, WHITE);
  DrawText(TextFormat("Score %d", player->score), 400, 400, 20, WHITE); 
  DrawText("Press ENTER to restart the game.", 400, 450, 14, WHITE);
  DrawText("Press ESC to quit the game.", 400, 500, 14, WHITE);
}

void drawLifePickup(struct LifePickup* lifePickup)
{
  DrawTexture(lifePickup->texture, lifePickup->position.x, lifePickup->position.y, WHITE);
  DrawRectangleLines(lifePickup->position.x,
		     lifePickup->position.y, 
		     lifePickup->hitBox.width, 
	             lifePickup->hitBox.height, 
      	             BLACK);
}

void drawExplosions(struct Explosion explosions[])
{
  for (int i = 0; i < MAXEXPLOSIONS; i++)
  {
    if (explosions[i].active == true)
    {
      DrawTexture(explosions[i].texture[explosions[i].index],
                  explosions[i].position.x,
                  explosions[i].position.y,
                  WHITE);
      explosions[i].index++;
    }

    if(explosions[i].index == MAXEXPLOSIONFRAMES)
    {
      explosions[i].index = 0;
      explosions[i].active = false;
    }

  }
}

void render(struct Screen* screen, struct Player* player, struct Game* game, struct Asteroid* head, struct Bullet bullets[], struct HealthBar* healthBar, struct LifePickup* lifePickup, struct Explosion explosions[])
{

  switch(screen->gameScreen)
  {
    case MENU:
    {
      ClearBackground(BLACK);
      drawMenuScreen();
      drawPlayerScore(player);
      drawPlayerLives(player);
      drawHealthBar(healthBar, player);
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
      drawLifePickup(lifePickup);
      drawExplosions(explosions); 
    } break;
    
    case GAMEOVER:
    {
      ClearBackground(BLACK);
      drawGameOverScreen(player);
    } break;

    case WONLEVEL:
    {
      ClearBackground(BLACK);
      drawLevelWinScreen(player);
    } break;

    case WONGAME:
    {
      ClearBackground(BLACK);
      drawGameWinScreen(player);
    } break;

      default: break;
  }
}
