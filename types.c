#include "types.h"
#include <stdio.h>
#include <stdlib.h>

struct Asteroid* createAsteroidNode()
{
  struct Asteroid* node = (struct Asteroid*)malloc(sizeof(struct Asteroid));
  
  if (node == NULL)
  {
    printf("Failed to allocate memory for asteroid node\n");
    exit(1);
  }
  
  node->collisionState = NOTHITTING;
  node->next = NULL;
  
  return node;
}

void pushAsteroid(struct Asteroid** head, struct Asteroid* node)
{
  if (*head == NULL)
  {
    *head = node;
  }
  else
  {
    struct Asteroid* current = *head;

    while (current->next != NULL)
    {
      current = current->next; 
    }
   
    current->next = node;
  }

}

void assignTokenToAsteroidValue(struct Asteroid* node, char* token, Texture2D smallAsteroidTexture, Texture2D mediumAsteroidTexture, Texture2D mediumAsteroidTexture2, Texture2D largeAsteroidTexture, Texture2D largeAsteroidTexture2, Texture2D largeAsteroidTexture3, int tokenNum)
{ 
  if (tokenNum == 0)
  {
    node->position.x = atoi(token);
    node->hitBox.x = atoi(token);
  }
  else if (tokenNum == 1)
  {
    node->position.y = atoi(token);
    node->hitBox.y = atoi(token);
  }
  else if (strcmp(token, "t") == 0 && tokenNum == 2)
  {
    node->hasItem = true;
  }
  else if (strcmp(token, "f") == 0 && tokenNum == 2)
  {
    node->hasItem = false;
  }
  else if (strcmp(token, "s\n") == 0)
  {
    node->currentTexture = 0;
    node->texture[node->currentTexture] = smallAsteroidTexture;
    node->hitBox.width = 16;
    node->hitBox.height = 16;
    node->points = 100;
    node->speed = 70;
    node->health = 1;
    node->damage = 1;
  }
  else if (strcmp(token, "m\n") == 0)
  {
    node->currentTexture = 0;
    node->texture[0] = mediumAsteroidTexture;
    node->texture[1] = mediumAsteroidTexture2;
    node->hitBox.width = 32;
    node->hitBox.height = 32;
    node->points = 200;
    node->speed = 80;
    node->health = 2;
    node->damage = 2;
  }
  else if (strcmp(token, "l\n") == 0)
  {
    node->currentTexture = 0;
    node->texture[0] = largeAsteroidTexture;
    node->texture[1] = largeAsteroidTexture2;
    node->texture[2] = largeAsteroidTexture3;
    node->hitBox.width = 64;
    node->hitBox.height = 64;
    node->points = 300;
    node->speed = 100;
    node->health = 3;
    node->damage = 3;
  }

}

void initialiseLevel(char* fileName, struct Asteroid** head)
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
  
  Texture2D smallAsteroidTexture = LoadTexture("assets/sprite/world/asteroid.png");
  Texture2D mediumAsteroidTexture = LoadTexture("assets/sprite/world/asteroidMedium.png");
  Texture2D mediumAsteroidTexture2 = LoadTexture("assets/sprite/world/asteroidMedium2.png");
  Texture2D largeAsteroidTexture = LoadTexture("assets/sprite/world/asteroidLarge.png");
  Texture2D largeAsteroidTexture2 = LoadTexture("assets/sprite/world/asteroidLarge2.png");
  Texture2D largeAsteroidTexture3 = LoadTexture("assets/sprite/world/asteroidLarge3.png");

  while (fgets(row, 1024, filePointer) != NULL)
  {

    int tokenNum = 0;
    token = strtok(row, ",");
    struct Asteroid *node = createAsteroidNode();
    
    while (token != NULL)
    {
      assignTokenToAsteroidValue(node, token, smallAsteroidTexture, 
		                 mediumAsteroidTexture, mediumAsteroidTexture2, largeAsteroidTexture, 
				 largeAsteroidTexture2, largeAsteroidTexture3, tokenNum);
      token = strtok(NULL, ",");
      tokenNum++;
    }

    pushAsteroid(head, node);
  }

  fclose(filePointer);
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
  
  head =  NULL;  
  printf("Asteroid inked list memory de-allocated\n\n");
}

void deleteAsteroid(struct Asteroid* current, struct Asteroid* previous, struct Asteroid** head)
{
  //remove the head of the linked list
  if (previous == NULL)
  {
    *head = current->next;
    free(current);
  }
  else //remove non-head node of the linked list
  { 
    previous->next = current->next;
    free(current);
  }
}

void resetExplosions(struct Explosion explosions[])
{
  for (int i = 0; i < MAXEXPLOSIONS; i++)
  {
    explosions[i].active = false;
    explosions[i].index = 0;
  }
}

