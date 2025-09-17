#include "raylib.h"
#include "types.h"

void screenHandler(struct Screen* screen, struct Game* game)
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
          
    default: break;
  }

}


