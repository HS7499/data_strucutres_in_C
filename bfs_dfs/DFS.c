#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node*next;
};

struct stack{
  struct node*top;
};
typedef struct stack stack;

stack *intialize(){
  stack*s=(stack*)malloc(sizeof(stack));
  s->top=NULL;
  return s;
}
int isempty(stack*s){
  return s->top==NULL;
}

void push(stack*s,int x){
  struct node*newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=x;
  newnode->next=s->top;
  s->top=newnode;
}

int pop(stack*s){
  struct node*topnode=(struct node*)malloc(sizeof(struct node));
  topnode=s->top;
  int value=topnode->data;
  s->top=topnode->next;
  free(topnode);
  return value;
}

void print(stack*s){
  struct node*temp=(struct node*)malloc(sizeof(struct node));
  temp=s->top;
  while(temp){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  
}

// graph4
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

//DFS recurrsive

void dfs(struct Graph*graph,int src,int n,int*visited){
    for (int i=0;i<n;i++){
      visited[i]=-1;
    }
    stack*s=intialize();
    push(s,src);

    visited[src]=1;
    printf("%d ",src);
    while(!isempty(s)){
      int curr=pop(s);
      if(visited[curr]==-1){
        push(s,curr);
        visited[curr]=1;
        printf("%d ",curr);
      }

      struct AdjListNode *neighbor=graph->vertices[curr].next;
      while(neighbor){
        int v=neighbor->vertex;
        if(visited[v]==-1){
            push(s,v);
            
        }
        neighbor=neighbor->next;
      }
    }

}


//


int main(){
  int n;
  scanf("%d",&n);
  struct Graph*G=createGraph(n);

  int m;
  scanf("%d",&m);

 int src;
  scanf("%d",&src);
  // int dest=n;
  for (int i=0;i<m;i++){
      int p,q;
      scanf("%d %d",&p,&q);
      addEdge(G,p,q);
  }

  int visited[n];
  // int path[n];
  dfs(G,src,n,visited);

}