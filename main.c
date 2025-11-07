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
#include "invulnFrames.c"
#include "item.c"
#include "audio.c"

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
	                    "levels/level2.csv",
  			    "levels/level3.csv"};
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
  PlayMusicStream(soundtrack); //raylib library function
  
  //health bar
  struct HealthBar healthBar;
  initHealthBar(&healthBar);

  //pickup item
  struct LifePickup lifePickup;
  initItem(&lifePickup);
  
  //explosion
  struct Explosion explosionArray[10];
  
  Texture2D texture1 = LoadTexture("assets/sprite/explosion/explosion1.png");
  Texture2D texture2 = LoadTexture("assets/sprite/explosion/explosion2.png");
  Texture2D texture3 = LoadTexture("assets/sprite/explosion/explosion3.png");
  Texture2D texture4 = LoadTexture("assets/sprite/explosion/explosion4.png");
  Texture2D texture5 = LoadTexture("assets/sprite/explosion/explosion5.png");
  Texture2D texture6 = LoadTexture("assets/sprite/explosion/explosion6.png");
  Texture2D texture7 = LoadTexture("assets/sprite/explosion/explosion7.png");
  Texture2D texture8 = LoadTexture("assets/sprite/explosion/explosion8.png");

  for (int i = 0; i < 10; i++)
  { 
    explosionArray[i].texture[0] = texture1;
    explosionArray[i].texture[1] = texture2;
    explosionArray[i].texture[2] = texture3;
    explosionArray[i].texture[3] = texture4;
    explosionArray[i].texture[4] = texture5;
    explosionArray[i].texture[5] = texture6;
    explosionArray[i].texture[6] = texture7;
    explosionArray[i].texture[7] = texture8;
    explosionArray[i].index = 0;
    explosionArray[i].active = false;
    explosionArray[i].playSound = false;
    explosionArray[i].sound = LoadSound("assets/sound/fart2.mp3"); 
  }

  //Main game loop
  while (game.gameState == PLAYING) 
  {
    //state handling
    screenHandler(&screen, &game, &player);
    levelChangeHandler(&asteroidHead, &game, &screen);
    levelHandler(&game, &player, bullets, &asteroidHead, levelFileNames, explosionArray);
    resetLifePickupLocation(&lifePickup, &game);
    controlsHandler(&player);        
    playerMovementHandler(&player, &screen);
    updatePlayerHitBox(&player);
    bulletSpawnHandler(&player, &game, bullets, bulletSounds, &audio);
    translateBullet(bullets, &game, &screen);
    moveAsteroids(&player, &screen, &game, asteroidHead);
    asteroidPlayerCollisionHandler(&player, &game, &asteroidHead);
    itemCollisionHandler(&lifePickup, &player, &game);
    bulletHitAsteroid(&asteroidHead, bullets, &game, &player, &lifePickup, explosionArray); 
    UpdateMusicStream(soundtrack); //raylib library function
    updatePlayerHealth(&player);
    updatePlayerLives(&player, &screen);
    updateInvulnFrames(&player);
    moveItem(&lifePickup, screenHeight);
    playExplosionSound(explosionArray);

    //print states to console
    /*printf("Move-state:%s Collision-state:%s \n", getPlayerMoveStateString(player.playerMoveState),
 		                                  getPlayerCollisionStateString(player.collisionState));
    */

    //Draw
    BeginDrawing();
      DrawFPS(0,0);
      render(&screen, &player, &game, asteroidHead, bullets, &healthBar, &lifePickup, explosionArray);
    EndDrawing();

    //reset states
    collisionCleanup(&player);
  }

  //De-Initialization
  freeAsteroidList(asteroidHead);
  deallocateShootingSoundFX(bulletSounds, &game);
  deallocateExplosionSoundFX(explosionArray);
  UnloadMusicStream(soundtrack);
  CloseAudioDevice();
  CloseWindow();        // Close window and OpenGL context
   
  return 0;
}
