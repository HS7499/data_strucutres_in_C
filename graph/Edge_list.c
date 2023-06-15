#include <stdio.h>
#include <stdlib.h>

// Declare a datatype that stores a single edge.

struct SingleEdge {
  int ep[2];
  struct SingleEdge *nextedge;
};

int main(void) {

  // To begin with, there was nothing.
  struct SingleEdge *head = NULL;
  head = (struct SingleEdge *)malloc(sizeof(struct SingleEdge));

  struct SingleEdge *current = NULL;
  current = (struct SingleEdge *)malloc(sizeof(struct SingleEdge));

  // head simply points to the first element of the list.
  // current will move forward as things get added.

  head->ep[0] = -1;
  head->ep[1] = -1;
  head->nextedge = current;

  // Read the number of edges.

  int m;
  scanf("%d", &m);
  int p,q;
  for (int i = 0; i < m; i++) {
    
    struct SingleEdge *newedge;

    newedge = (struct SingleEdge *)malloc(sizeof(struct SingleEdge));
    scanf("%d %d",&p,&q);
    newedge->ep[0] = p;
    newedge->ep[1] = q;
    newedge->nextedge = NULL;
    // Populate the newedge struct
    // with information about the current edge.

    current->nextedge = newedge;
    current = newedge;
  }

  struct SingleEdge *navigator = head->nextedge;
  int degree = 0;
  int vertex;

  scanf("%d", &vertex);

  while (navigator != NULL) {
    // CHECK IF "vertex" is an endpoint
    // of the current edge being explored.
    if (navigator -> ep[0] == vertex || navigator -> ep[1] == vertex) {
      degree = degree + 1;
    }
    navigator = navigator->nextedge;
  }

  printf("%d", degree);

  return 0;
}
