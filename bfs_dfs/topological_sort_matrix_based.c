#include <stdio.h>
 
int main(){
int n;
scanf("%d",&n);
int i,j,k,a[n][n],indeg[n],flag[n],count=0;

for(i=0;i<n;i++){
for(j=0;j<n;j++)
a[i][j] =0;
}
int p,q;
for (int i=0;i<n;i++){
    scanf("%d %d",&p,&q);
    a[p][q]=1;
}

 
for(i=0;i<n;i++){
        indeg[i]=0;
        flag[i]=0;
    }
 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            indeg[i]=indeg[i]+a[j][i];
 
    printf("\nThe topological order is:");
 
    while(count<n){
        for(k=0;k<n;k++){
            if((indeg[k]==0) && (flag[k]==0)){
                printf("%d ",(k+1));
                flag [k]=1;
            }
 
            for(i=0;i<n;i++){
                if(a[i][k]==1)
                    indeg[k]--;
            }
        }
 
        count++;
    }
 
    return 0;
}