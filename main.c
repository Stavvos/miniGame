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
  initScreen(&screen); 

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
  Sound bulletSounds[game.MAXBULLETS];
  initAudio(&audio, &game, bulletSounds);
  Music soundtrack = LoadMusicStream("assets/musicTracks/emeraldSeas.mp3");
  PlayMusicStream(soundtrack);
  
  //health bar
  struct HealthBar healthBar;
  initHealthBar(&healthBar);

  //Main game loop
  while (game.gameState == PLAYING) 
  {
    //state handling
    screenHandler(&screen, &game, &player); 
    controlsHandler(&player);        
    playerMovementHandler(&player, &screen);
    updatePlayerHitBox(&player);
    bulletSpawnHandler(&player, &game, bullets, bulletSounds, &audio);
    translateBullet(bullets, &game, &screen);
    moveAsteroids(&player, &screen, &game, head);
    collisionHandler(&player, &game, &head);
    bulletHitAsteroid(&head, bullets, &game); 
    UpdateMusicStream(soundtrack);
    
    //reset players health 
    if(player.playerHealth == 0)
    {
      player.playerHealth = 5;
      player.playerLives--;
    }
    
    if(player.playerLives == -1)
    {
      screen.gameScreen = GAMEOVER;
    }

    //print states to console
    printf("Move-state:%s Collision-state:%s \n", getPlayerMoveStateString(player.playerMoveState),
 		                                  getPlayerCollisionStateString(player.collisionState));

    //Draw
    BeginDrawing();
      DrawFPS(0,0);
      render(&screen, &player, &game, head, bullets, &healthBar);
    EndDrawing();

    //reset states
    collisionCleanup(&player);
  }

  //De-Initialization
  freeAsteroidList(head);
  deallocateSoundFX(bulletSounds, &game);
  UnloadMusicStream(soundtrack);
  CloseAudioDevice();
  CloseWindow();        // Close window and OpenGL context
  return 0;
}
