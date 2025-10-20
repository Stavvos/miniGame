#include <stdlib.h>
#include "raylib.h"
#include "math.h"
#include "stdio.h"
#include "types.h"
#include "controls.c"
#include "screens.c"
#include "movement.c"
#include "render.c"
#include "collision.c"
#include "testing.c"
#include "asteroidMovement.c"
#include "bullet.c"
#include "initialise.c"
#include "deallocate.c"

int main(void)
{
  const int screenWidth = GetScreenWidth();
  const int screenHeight = GetScreenHeight();	
  InitWindow(screenWidth, screenHeight, "game");
  SetTargetFPS(60);
  HideCursor();

  struct Player player;
  initPlayer(&player);
  
  struct Game game;
  initGame(&game);

  struct Screen screen;
  screen.gameScreen = MENU;
  
  Texture2D mediumAsteroidTexture = LoadTexture("assets/sprite/world/asteroidMedium.png");
  Texture2D largeAsteroidTexture = LoadTexture("assets/sprite/world/asteroidLarge.png");
  
  //asteroid linked list initialisation 
  asteroid* head = NULL;
  head = (asteroid*) malloc(sizeof(asteroid));
  initAsteroids(head);
  
  //initialise bullets
  struct Bullet bullets[game.MAXBULLETS];
  initBullets(bullets, &game);
  
  //initialise audio device for raylib
  InitAudioDevice();
  
  //init audio  
  struct Audio audio;
  Sound sounds[game.MAXBULLETS];
  initAudio(&audio, &game, sounds);
  
  Music soundtrack = LoadMusicStream("assets/musicTracks/emeraldSeas.mp3");
  PlayMusicStream(soundtrack);
  
  //health bar
  player.playerHealth = 5;
  const Rectangle healthBarBackground = {10, 20, 50, 10};
  Rectangle healthBarForgroundBlock = {0, 0, 0, 0};
  Rectangle healthBarForgroundBlocks[5];
 
  int offSet = 1; 
  for (int i = 0; i < player.playerHealth; i++)
  {
    healthBarForgroundBlocks[i].x = healthBarBackground.x + offSet;
    healthBarForgroundBlocks[i].y = healthBarBackground.y + 1;
    healthBarForgroundBlocks[i].width = healthBarBackground.width - 42;
    healthBarForgroundBlocks[i].height = healthBarBackground.height - 2;
    offSet += healthBarBackground.x;
  }

  // Main game loop
  while (game.gameState == PLAYING) 
  {
    //state handling
    screenHandler(&screen, &game); 
    controlsHandler(&player, bullets, &game, sounds, &audio);        
    playerMovementHandler(&player, &screen);
    updatePlayerHitBox(&player);
    translateBullet(bullets, &game, &screen);
    moveAsteroids(&player, &screen, &game, head);
    collisionHandler(&player, &game, &head);
    bulletHitAsteroid(&head, bullets, &game); 

    UpdateMusicStream(soundtrack);
    //print states to console
    printf("Move-state:%s Collision-state:%s \n", getPlayerMoveStateString(player.playerMoveState),
 		                                  getPlayerCollisionStateString(player.collisionState));

    //Draw
    BeginDrawing();
      DrawFPS(0,0);
      render(&screen, &player, &game, head, bullets);
      DrawRectangle(healthBarBackground.x, healthBarBackground.y, healthBarBackground.width, healthBarBackground.height, BLACK);
      
      for (int i = 0; i < player.playerHealth; i++)
      {
        
        DrawRectangle(healthBarForgroundBlocks[i].x, 
		      healthBarForgroundBlocks[i].y, 
		      healthBarForgroundBlocks[i].width, 
		      healthBarForgroundBlocks[i].height, 
		      GREEN);
      }

    EndDrawing();

    //reset states
    collisionCleanup(&player);
  }

  // De-Initialization
  freeAsteroidList(head);
  deallocateSoundFX(sounds, &game);
  UnloadMusicStream(soundtrack);
  CloseAudioDevice();
  CloseWindow();        // Close window and OpenGL context
  return 0;
}
