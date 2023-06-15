#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

struct node {
    int vertex;
    struct node* next;
};

struct graph {
    struct node* adjList[MAX_VERTICES];
    int visited[MAX_VERTICES];
};

struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct graph* g, int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;
}

void dfs_iterative(int vertex, struct graph* g, int stack[], int* top) {
    struct node* temp;
    stack[++(*top)] = vertex;
    while (*top >= 0) {
        int v = stack[(*top)--];
        if (!g->visited[v]) {
            g->visited[v] = 1;
            for (temp = g->adjList[v]; temp != NULL; temp = temp->next) {
                if (!g->visited[temp->vertex]) {
                    stack[++(*top)] = temp->vertex;
                }
            }
        }
    }
}

void topological_sort(struct graph* g, int n) {
    int i, top = -1;
    int stack[MAX_VERTICES];
    for (i = 0; i < n; i++) {
        g->visited[i] = 0;
    }
    top = -1;
    for (i = 0; i < n; i++) {
        if (!g->visited[i]) {
            dfs_iterative(i, g, stack, &top);
        }
    }
    printf("Topological Sort: ");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, m, i;
    struct graph* g = malloc(sizeof(struct graph));
    for (i = 0; i < MAX_VERTICES; i++) {
        g->adjList[i] = NULL;
    }
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges: ");
    for (i = 0; i < m; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }
    topological_sort(g, n);
    return 0;
}
