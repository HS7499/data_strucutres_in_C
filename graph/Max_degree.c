// Adjacency Matrix representation in C
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int m;
  scanf("%d", &m);

  int G[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      G[i][j] = 0;

  for (int i = 0; i < m; i++) {
    int u,v;
    scanf("%d %d",&u,&v);

    G[u][v]=1;
    G[v][u]=1;

  }

  int maxdegree = 0;
  int max=0;

  // Write the logic to print the maxdegree of the graph here.
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
        if (G[i][j]==1){
            max++;
        }
    }

    if (maxdegree < max){
        maxdegree=max;
        
    }
    max=0;
  }

  printf("%d", maxdegree);
  return 0;

}
