#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100 // maximum number of nodes in the graph

// queue structure for BFS traversal
typedef struct {
    int data[MAX_NODES];
    int front, rear;
} Queue;

// initialize the queue
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

// check if the queue is empty
int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

// check if the queue is full
int isQueueFull(Queue *q) {
    return q->rear == MAX_NODES-1;
}

// add an element to the queue
void enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue overflow\n");
        exit(1);
    }
    if (isQueueEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->data[q->rear] = value;
}

// remove an element from the queue
int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue underflow\n");
        exit(1);
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// breadth-first search algorithm to find the shortest path
void bfs(int graph[MAX_NODES][MAX_NODES], int num_nodes, int source, int destination) {
    int visited[MAX_NODES] = {0}; // array to mark visited nodes
    int distance[MAX_NODES] = {0}; // array to store the shortest distance from source to each node
    int parent[MAX_NODES] = {0}; // array to store the parent of each node in the shortest path
    Queue q;
    initQueue(&q);
    visited[source] = 1;
    enqueue(&q, source);
    while (!isQueueEmpty(&q)) {
        int current_node = dequeue(&q);
        for (int i = 0; i < num_nodes; i++) {
            if (graph[current_node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                distance[i] = distance[current_node] + 1;
                parent[i] = current_node;
                enqueue(&q, i);
            }
        }
    }

    // print the shortest path from source to destination
    // printf("Shortest path from %d to %d: ", source, destination);
    int node = destination;
    printf("%d", node);
    while (node != source) {
        node = parent[node];
        printf(" <- %d", node);
    }
    printf("\n");
    printf("Shortest distance from %d to %d: %d\n", source, destination, distance[destination]);
}

int main() {
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);
    int graph[MAX_NODES][MAX_NODES] = {0}; // adjacency matrix to represent the graph
    int source =0;
    int destination =num_nodes-1;
    for (int i = 0; i < num_edges; i++) {
        int node1, node2;
        scanf("%d %d",&node1,&node2);
        graph[node1][node2]=1;
    }
    bfs(graph,num_nodes,source,destination);
}