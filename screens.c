#include "raylib.h"
#include "types.h"

void screenHandler(struct Screen* screen, struct Game* game, struct Player* player)
{
  //Update game screen state 
  switch(screen->gameScreen)
  {
    case MENU:
    {
      if (IsKeyPressed(KEY_ENTER))
      {
        screen->gameScreen = GAMEPLAY;
      }
      
      if (IsKeyPressed(KEY_C))
      {
        screen->gameScreen = CONTROLS;
      }

      if (IsKeyPressed(KEY_ESCAPE))
      {
        game->gameState = EXIT;
      }
    } break;
    
    case CONTROLS:
    {
      if (IsKeyPressed(KEY_ENTER))
      {
        screen->gameScreen = MENU;
      }
    } break;

    case GAMEPLAY:
    {
      if (IsKeyPressed(KEY_ESCAPE))
      {
        screen->gameScreen = MENU;
      }
    } break;
    
    case GAMEOVER:
    {
      if (IsKeyPressed(KEY_ENTER))
      {
        screen->gameScreen = GAMEPLAY;
	player->playerLives = PLAYERLIVES;
	player->playerHealth = PLAYERHEALTH;
	game->gameState = RESETLEVEL;
	game->level = 0;
	player->score = 0;
	game->resetItemLocation = true;
      }

      if (IsKeyPressed(KEY_ESCAPE))
      {
        game->gameState = EXIT;
      }
    } break;
    
    case WONLEVEL:
    {
      if (IsKeyPressed(KEY_ENTER))
      {
        screen->gameScreen = GAMEPLAY;
	game->gameState = RESETLEVEL;
	game->resetItemLocation = true;
      }

      if (IsKeyPressed(KEY_ESCAPE))
      {
        game->gameState = EXIT;
      }
    } break;
    
    case WONGAME:
    {
      if (IsKeyPressed(KEY_ENTER))
      {
	screen->gameScreen = GAMEPLAY;
	player->playerLives = PLAYERLIVES;
	player->playerHealth = PLAYERHEALTH;
	game->gameState = RESETLEVEL;
	player->score = 0;
	game->resetItemLocation = true;
      }

      if (IsKeyPressed(KEY_ESCAPE))
      {
        game->gameState = EXIT;
      }
    } break;
    
      default: break;
  }

}


