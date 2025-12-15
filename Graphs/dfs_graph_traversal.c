#include <stdio.h>
#include <stdlib.h>

int visited[4] = {0};

    int a[4][4] = {
    {0,1,1,0},
    {1,0,0,1},
    {1,0,0,1},
    {0,1,1,0}
};

void DFS(int start){
    printf("%d ", start);
    visited[start] = 1;
    for(int j=0; j<4; j++){
        if(a[start][j] == 1 && !visited[j]){
            DFS(j);
        }
    }
}

int main(){
    DFS(0);
    return 0;
}