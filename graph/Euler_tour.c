#include <stdio.h>
#include <stdlib.h>

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
  
  int degree = 0;
  int count = 0;
  
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
        if (G[i][j]==1){
            degree++;
        }
    }
    if(degree%2 != 0){
      count ++;
    }
  }

  if(count >= 3){
    printf("NO\n");
  }
  else{
  printf("YES\n");
  } 
  return 0;
}
