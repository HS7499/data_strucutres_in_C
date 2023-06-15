#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *next;

};

struct queue{
    struct node*front;
    struct node*rear;
};

typedef struct queue queue;

 queue *initialize(){
    queue*q=(queue*)malloc(sizeof(queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

int isempty(queue *q){
    return q->front==NULL;
}

void push(queue*q,int value){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if (isempty(q)){
      q->rear = newnode;
      q->front = newnode;
    }else {
      q->rear->next=newnode;
      q->rear=newnode;    
    }
}

int pop(queue*q){
    if (isempty(q)){
        printf("underflow");
        return -1;
    }else {
        struct node*topnode=q->front;
        int value =topnode->data;
        q->front =topnode->next;
        free(topnode);
        return value;
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

void bfs(struct Graph*graph,int* visited,int n,int src){
    
    for (int i=0;i<n;i++){
        visited[i]=-1;
    }
    queue *q =initialize();
    visited[src]=1;
    push(q,src);
    while(!isempty(q)){
        int curr=pop(q);
        
        struct AdjListNode *neighbor=graph->vertices[curr].next;

        while(neighbor){
            int v=neighbor->vertex;
            if (visited[v]== -1){
                visited[v]= 1;
                push(q,v);
                
            }
            //we can print vertex here
            neighbor=neighbor->next;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    struct Graph*g=createGraph(n);
    int m;
    scanf("%d",&m);
    int src;
    scanf("%d",&src);
    // int dest=n;
    for (int i=0;i<m;i++){
        int p,q;
        scanf("%d %d",&p,&q);
        addEdge(g,p,q);
    }
     int visited[n];
    bfs(g,visited,n,src);

    for (int i=0;i<n;i++){
        printf("%d ",visited[i]);
    }   
}

