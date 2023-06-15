#include <stdio.h>
#include <stdlib.h>

typedef struct s_card {
  int cardvalue;
  struct s_card *next;
  struct s_card *prev;
} t_card;

typedef struct s_cardstack {
  struct s_card *first;
  struct s_card *last;
} t_cardstack;

t_cardstack *cardstackInit() {
  t_cardstack *cardstack;
  cardstack = malloc(sizeof(t_cardstack));
  cardstack->first = NULL;
  cardstack->last = NULL;
  return cardstack;
}

int isEmpty(t_cardstack *cardstack) { return !cardstack->first; }

void pushFront(t_cardstack *cardstack, int cardvalue) {
  t_card *node = malloc(sizeof(t_card));
  node->cardvalue = cardvalue;
  node->prev = NULL;
  node->next = cardstack->first;
  if (isEmpty(cardstack))
    cardstack->last = node;
  else
    cardstack->first->prev = node;
  cardstack->first = node;
}

void pushBack(t_cardstack *cardstack, int cardvalue) {
  t_card *node = malloc(sizeof(t_card));
  node->cardvalue = cardvalue;
  node->prev = cardstack->last;
  node->next = NULL;
  if (isEmpty(cardstack))
    cardstack->first = node;
  else
    cardstack->last->next = node;
  cardstack->last = node;
}

int popFront(t_cardstack *cardstack) {
  t_card *node;
  int cardvalue;
  if (isEmpty(cardstack))
    return -1;
  node = cardstack->first;
  cardstack->first = node->next;
  if (!cardstack->first)
    cardstack->last = NULL;
  else
    cardstack->first->prev = NULL;
  cardvalue = node->cardvalue;
  free(node);
  return cardvalue;
}

int popBack(t_cardstack *cardstack) {
  t_card *node;
  int cardvalue;
  if (isEmpty(cardstack))
    return -1;
  node = cardstack->last;
  cardstack->last = node->prev;
  if (!cardstack->last)
    cardstack->first = NULL;
  else
    cardstack->last->next = NULL;
  cardvalue = node->cardvalue;
  free(node);
  return cardvalue;
}

int peekFront(t_cardstack *cardstack) {
  if (isEmpty(cardstack))
    return -1;
  return cardstack->first->cardvalue;
}

int peekBack(t_cardstack *cardstack) {
  if (isEmpty(cardstack))
    return -1;
  return cardstack->last->cardvalue;
}


void fronttoback(t_cardstack *cardstack) {
  if (isEmpty(cardstack)){
    return ;
  }
  else{ 
    t_card *currpointer = cardstack->last; 
    int k = 0; 
    while (currpointer) {
      if (k%2==0){  
        printf("%d\n",currpointer->cardvalue); 
      }
      currpointer = currpointer->prev;
      k++;  
    }
  }
}

int main()
{ 

  int n;
  scanf("%d", &n);
  int x,y;
  t_cardstack *firststack = cardstackInit();
  
  for (int i = 0; i < n; i++) {
    
    scanf("%d %d", &x,&y);
    if (x==1){
      pushBack(firststack, y);
    }
    else{
      pushFront(firststack, y);
    }
  }
  
  fronttoback(firststack);
  

  return 0;

  }