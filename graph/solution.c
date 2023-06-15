#include <stdio.h>
#include <stdlib.h>

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

// Adds an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest) {
  // Add an edge from src to dest.  A new node is added to the adjacency
  // list of src.  The node is added at the begining
  struct AdjListNode *newNode = newAdjListNode(dest);
  newNode->next = graph->vertices[src].next;
  graph->vertices[src].next = newNode;

  // Since graph is undirected, add an edge from dest to src also. Write this
  // part below.
  newNode = newAdjListNode(src);
  newNode->next = graph->vertices[dest].next;
  graph->vertices[dest].next = newNode;
}

int main() {

  int n;
  scanf("%d", &n);

  struct Graph *G = createGraph(n);

  int m;
  scanf("%d", &m);

  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d", &u);
    scanf("%d", &v);
    addEdge(G, u, v);
  }

  int x, y;

  scanf("%d %d", &x, &y);

  int sum = 0;

  struct AdjListNode *temp1 = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
  struct AdjListNode *temp2 = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));

  temp1 = G->vertices[x].next;
  while (temp1) {
    int vertex = temp1->vertex;
    temp2 = G->vertices[y].next;
    while (temp2) {
      if (temp2->vertex == vertex) {
        sum++;
        break;
      }
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
  }

  printf("%d", sum);

  return 0;
}

