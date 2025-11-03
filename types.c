#include "types.h"
#include <stdio.h>
#include <stdlib.h>

void readLevelFile(char* fileName)
{
  FILE *filePointer;
  char row[1024];
  char *token;

  filePointer = fopen(fileName, "r");

  if (filePointer == NULL)
  {
    printf("Error opening level file");
    return;
  }

  while(fgets(row, 1024, filePointer) != NULL)
  {

    printf("Row: %s", row);
    token = strtok(row, ",");
    
    while (token != NULL)
    {
      printf("Token: %s\n", token);
      token = strtok(NULL, ",");
    }
  }

  fclose(filePointer);
}

void initAsteroids(struct Asteroid* head)
{

  Texture2D smallAsteroidTexture = LoadTexture("assets/sprite/world/asteroid.png");
  Texture2D mediumAsteroidTexture = LoadTexture("assets/sprite/world/asteroidMedium.png");
  Texture2D largeAsteroidTexture = LoadTexture("assets/sprite/world/asteroidLarge.png");

  head->texture = smallAsteroidTexture;
  head->position = (Vector2){100.f, 100.f};
  head->hitBox.width = 16;
  head->hitBox.height = 16;
  head->hitBox.x = head->position.x;
  head->hitBox.y = head->position.y;
  head->collisionState = NOTHITTING;
  head->next = NULL;

  int offsetX = 5;
  int offsetY = 5;

  for (int i = 0; i < 100; i++)
  {
    if(i == 10)
    {
      pushAsteroid(head, largeAsteroidTexture, offsetX, offsetY);
    }
    else if (i == 33)
    {
      pushAsteroid(head, mediumAsteroidTexture, offsetX, offsetY);
    }
    else
    {
      pushAsteroid(head, smallAsteroidTexture, offsetX, offsetY);
    }

    offsetX += 5;
    offsetY += 0;
  }

}

void pushAsteroid(struct Asteroid* head, Texture2D texture, int offsetX, int offsetY)
{
  struct Asteroid* current = head;

  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = (struct Asteroid*) malloc(sizeof(struct Asteroid));
  current->next->texture = texture;
  current->next->position = (Vector2){100.f + offsetX, 100.f + offsetY};
  current->next->hitBox.width = 16;
  current->next->hitBox.height = 16;
  current->next->hitBox.x = current->next->position.x;
  current->next->hitBox.y = current->next->position.y;
  current->next->collisionState = NOTHITTING;
  current->next->next = NULL;
}

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

void deleteAsteroid(struct Asteroid* current, struct Asteroid* previous, struct Asteroid** head)
{
  //remove the head of the linked list
  if(previous == NULL)
  {
    *head = current->next;
    free(current);
  }
  else //remove other node of the linked list
  { 
    previous->next = current->next;
    free(current);
  }
}

