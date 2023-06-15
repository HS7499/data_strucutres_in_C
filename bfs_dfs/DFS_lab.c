#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//////  cardstack

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

void *fronttoback(t_cardstack *cardstack) {
  if (isEmpty(cardstack))
    return NULL;
  t_card *currpointer = cardstack->last;
  while (currpointer) {
    printf("%d\n", currpointer->cardvalue);
    currpointer = currpointer->prev;
  }
}

///////////// Graph Representation
// A structure to represent an adjacency list node
struct AdjListNode {
  int vertex;
  struct AdjListNode *next;
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph {
  int n;
  struct AdjListNode *vertices;
};

// A utility function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int v) {
  struct AdjListNode *newNode =
      (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph *createGraph(int V) {
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->n = V;

  graph->vertices =
      (struct AdjListNode *)malloc(V * sizeof(struct AdjListNode));
  int i;
  for (i = 0; i < V; ++i) {
    graph->vertices[i].next = NULL;
    graph->vertices[i].vertex = -1;
  }

  return graph;
}
void addEdge(struct Graph *graph, int src, int dest) {
  // Add an edge from src to dest.  A new node is added to the adjacency
  // list of src.  The node is added at the begining
  struct AdjListNode *newNode = newAdjListNode(dest);
  // push into the list in lexicographic sequence
  if (graph->vertices[src].next == NULL) {
    newNode->next = graph->vertices[src].next;
    graph->vertices[src].next = newNode;
  } else {
    struct AdjListNode *curr = graph->vertices[src].next;
    struct AdjListNode *slow = &graph->vertices[src];
    while (curr != NULL && (dest < curr->vertex)) {
      // keep going forward
      // if (curr == NULL) break;
      slow = curr;
      curr = curr->next;
    }
    newNode->next = curr;
    slow->next = newNode;
  }

  // Since graph is undirected, add an edge from dest to src also.

  struct AdjListNode *newNode2 = newAdjListNode(src);
  if (graph->vertices[dest].next == NULL) {
    newNode2->next = graph->vertices[dest].next;
    graph->vertices[dest].next = newNode2;
  } else {
    struct AdjListNode *curr1 = graph->vertices[dest].next;
    struct AdjListNode *slow1 = &graph->vertices[dest];
    while (curr1 != NULL && (src < curr1->vertex)) {
      // keep going forward
      // if (curr1 == NULL) break;
      slow1 = curr1;
      curr1 = curr1->next;
    }
    newNode2->next = curr1;
    slow1->next = newNode2;
  }
}
void dfs(struct Graph *G, int src, int size) {
  bool visited[size];

  for (int i = 0; i < size; i++)
    visited[i] = false;

  t_cardstack *stack = cardstackInit();
  pushBack(stack, src);

  while (!isEmpty(stack)) {
    int curr = popBack(stack);
    if (!visited[curr]) {
      visited[curr] = true;
      printf("%d ", curr);
    }

    // iterator
    struct AdjListNode *temp = G->vertices[curr].next;

    while (temp) {
      if (!visited[temp->vertex]) {
        pushBack(stack, temp->vertex);
      }
      temp = temp->next;
      // increase the iterator
    }
  }
}

int main() {

  int n;
  scanf("%d", &n);

  struct Graph *G = createGraph(n);

  int m;
  scanf("%d", &m);

  int s;
  scanf("%d", &s);

  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d", &u);
    scanf("%d", &v);
    addEdge(G, u, v);
  }

  dfs(G, s, n);

  // Write your solution here.

  return 0;
}