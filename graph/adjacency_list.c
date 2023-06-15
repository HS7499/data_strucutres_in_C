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
  struct AdjListNode* vertices;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int v) {
  struct AdjListNode *newNode =
      (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph *createGraph(int V) {
  struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->n = V;
  
  graph->vertices = (struct AdjListNode*) malloc(V * sizeof(struct AdjListNode));
  int i;
  for (i = 0; i < V; ++i){
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

  // Since graph is undirected, add an edge from dest to src also. Write this part below.
  // ...
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

    //go to the adjacency list of x;
    struct AdjListNode *temp=newAdjListNode(x);
    temp->next = G->vertices[x].next;
    temp->vertex=G->vertices[x].vertex;

    while (temp!=0){
      printf("%d ",temp->vertex);
    }
    
    
    

  return 0;
}   