#include "raylib.h"
#include "types.h"

void screenHandler(struct Screen* screen, struct Game* game, struct Player* player)
{
  //Update game screen state 
  switch(screen->gameScreen)
  {
    case MENU:
    {
      if(IsKeyPressed(KEY_ENTER))
      {
        screen->gameScreen = GAMEPLAY;
      }

      if(IsKeyPressed(KEY_ESCAPE))
      {
        game->gameState = EXIT;
      }
    } break;

    case GAMEPLAY:
    {
      if(IsKeyPressed(KEY_ESCAPE))
      {
        screen->gameScreen = MENU;
      }
    } break;
    
    case GAMEOVER:
    {
      if(IsKeyPressed(KEY_ENTER))
      {
        screen->gameScreen = GAMEPLAY;
	player->playerLives = PLAYERLIVES;
      }

      if(IsKeyPressed(KEY_ESCAPE))
      {
        game->gameState = EXIT;
      }
    } break;

      default: break;
  }

}


