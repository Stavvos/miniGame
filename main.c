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
#include "lives.c"
#include "health.c"
#include "level.c"

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
  initScreen(&screen); 
  
  //asteroid linked list initialisation 
  struct Asteroid* asteroidHead = NULL;
  char *levelFileNames[] = {"levels/level1.csv",
	                    "levels/level2.csv"};
  initialiseLevel(levelFileNames[game.level], &asteroidHead);
  
  //initialise bullets
  struct Bullet bullets[game.MAXBULLETS];
  initBullets(bullets, &game);
  
  //initialise audio device for raylib
  InitAudioDevice();
  
  //init audio  
  struct Audio audio;
  Sound bulletSounds[game.MAXBULLETS];
  initAudio(&audio, &game, bulletSounds);
  Music soundtrack = LoadMusicStream("assets/musicTracks/emeraldSeas.mp3");
  PlayMusicStream(soundtrack);//raylib library function
  
  //health bar
  struct HealthBar healthBar;
  initHealthBar(&healthBar);

  //Main game loop
  while (game.gameState == PLAYING) 
  {
    //state handling
    screenHandler(&screen, &game, &player);
    levelChangeHandler(&asteroidHead, &game, &screen);
    levelHandler(&game, &player, bullets, &asteroidHead, levelFileNames);
    controlsHandler(&player);        
    playerMovementHandler(&player, &screen);
    updatePlayerHitBox(&player);
    bulletSpawnHandler(&player, &game, bullets, bulletSounds, &audio);
    translateBullet(bullets, &game, &screen);
    moveAsteroids(&player, &screen, &game, asteroidHead);
    collisionHandler(&player, &game, &asteroidHead);
    bulletHitAsteroid(&asteroidHead, bullets, &game, &player); 
    UpdateMusicStream(soundtrack); //raylib library function
    updatePlayerHealth(&player);
    updatePlayerLives(&player, &screen);

    //print states to console
    printf("Move-state:%s Collision-state:%s \n", getPlayerMoveStateString(player.playerMoveState),
 		                                  getPlayerCollisionStateString(player.collisionState));

    //Draw
    BeginDrawing();
      DrawFPS(0,0);
      render(&screen, &player, &game, asteroidHead, bullets, &healthBar);
    EndDrawing();

    //reset states
    collisionCleanup(&player);
  }

  //De-Initialization
  freeAsteroidList(asteroidHead);
  deallocateSoundFX(bulletSounds, &game);
  UnloadMusicStream(soundtrack);
  CloseAudioDevice();
  CloseWindow();        // Close window and OpenGL context
   
  return 0;
}
