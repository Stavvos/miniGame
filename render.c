#include "raylib.h"
#include "types.h"


void render(struct Screen* screen, struct Player* player, struct Enemy* enemy)
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
      DrawTexture(enemy->asteroidSmall, 100.f, 100.f, WHITE);
      DrawTexture(enemy->asteroidMedium, 200.f, 600.f, WHITE);
      DrawTexture(enemy->asteroidLarge, 920.f, 510.f, WHITE);
    } break;

      default: break;
  }
}
