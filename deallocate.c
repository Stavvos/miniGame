#include "raylib.h"

void freeAsteroidList(struct Asteroid* head)
{
  printf("\n\nDe-allocating asteroid linked list memory\n");
  
  struct Asteroid* current = head;
  struct Asteroid* nextNode;
  
  while (current != NULL)
  {
    nextNode = current->next;
    free(current);
    current = nextNode;
  }

  printf("Asteroid inked list memory de-allocated\n\n");
}

void deallocateSoundFX(Sound sounds[], struct Game* game)
{
  for(int i = 0; i < game->MAXBULLETS; i++)
  {
    UnloadSound(sounds[i]);
  }
}

