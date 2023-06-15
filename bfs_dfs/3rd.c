#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node {
  int data;
  struct node *next;
};
typedef struct node node;

struct queue {
  node *front;
  node *rear;
};
typedef struct queue queue;

queue *initialize() {
  queue *q = (queue *)malloc(sizeof(queue));
  q->front = NULL;
  q->rear = NULL;
  return q;
}

int isEmpty(queue *q) { return (q->front == NULL); }

void push(queue *q, int value) {
  node *tmp = (node *)malloc(sizeof(node));
  tmp->data = value;
  tmp->next = NULL;
  if (!isEmpty(q)) {
    q->rear->next = tmp;
    q->rear = tmp;
  } else {
    q->front = q->rear = tmp;
  }
}

int pop(queue *q) {
  node *tmp = q->front;
  int n = q->front->data;
  q->front = q->front->next;
  free(tmp);
  return (n);
}

void display(node *head) {
  if (head == NULL) {
    printf("NULL\n");
  } else {
    printf("%d\n", head->data);
    display(head->next);
  }
}

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
/*

        0
      / | \
     1  3  5
    / \     \
   6   2     4

*/
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
    while (curr != NULL && (dest > curr->vertex)) {
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
    while (curr1 != NULL && (src > curr1->vertex)) {
      // keep going forward
      // if (curr1 == NULL) break;
      slow1 = curr1;
      curr1 = curr1->next;
    }
    newNode2->next = curr1;
    slow1->next = newNode2;
  }
}

int main() {

  // START: READING INPUT //

  int n;
  scanf("%d", &n);

  struct Graph *G = createGraph(n);

  int m =n-1;
//   scanf("%d", &m);

  int s=1;
//   scanf("%d", &s);

  for (int j = 0; j < m; j++) {
    int u, v;
    scanf("%d", &u);
    scanf("%d", &v);
    addEdge(G, u, v);
  }

  // FINISH: READING INPUT //

  int visited[n];
  // initialize visited array
  for (int i = 0; i < n; i++) {
    // all unvisited vertices are labled -1
    visited[i] = -1;
  }

  // s is visited in round 0
  visited[s] = 0;

  // Initialize an empty queue:
  queue *q = initialize();

  // add s to the head
  push(q, s);

  // print s as the round 0 vertex.
  printf("%d", s);

  // helper variables
  int round = 0;
  int flag = 0;

  while (!isEmpty(q)) {
    // pop the front element of the queue.
    int current = pop(q);
    if (round != visited[current] + 1) {
      printf("\n");
    }
    round = visited[current] + 1;
    // get the first neighbor of current
    struct AdjListNode *neighbor = G->vertices[current].next;
    int startflag = TRUE;
    // now loop through the neighbors of current
    while (neighbor) {

      // get the ID of the neighbor.
      int v = neighbor->vertex;
      // check if v is visited
      if (visited[v] == -1) {
        // updated visited[v] to the round number.
        visited[v] = round;
        // push v to the back of the queue.
        push(q, v);
        // print v:
        if (startflag) {
          printf("%d", v);
          startflag = FALSE;
        } else {
          printf(" %d", v);
        }

        flag = 1; // something got printed.
      }
      // remember to move on to the next neighbor!!!
      neighbor = neighbor->next;
    }
  }

    You might want to check out the state of the visited array:
  for (int k = 0; k < n; k++)
  {
      printf("%d\t", visited[k]);
  }
  // printf("\n***********\nPrinting Level Order Using Visited
  // Array\n****************");

  // for (int r = 0; r <= max_round; r++)
  // {
  //     printf("\n");
  //     for (int i = 0; i < n; i++)
  //     {
  //         if (visited[i] == r)
  //             printf("%d ", i);
  //     }
  // }

  return 0;
}