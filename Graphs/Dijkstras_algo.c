#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 5

int minDistance(int dist[] , int visited[]){
    int min = INT_MAX;
    int min_index;

    for(int i=0; i<V; i++){
        if(visited[i] == 0 && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printSolution(int dist[]){
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijktras(int graph[V][V] , int src){
    int dist[V];
    int visited[V];

    for(int i=0; i<V; i++){ // initially define all the distances as infinite and visited false
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0; // distance of the src (0) to itself is 0 initialize that

    for(int count = 0; count < V-1; count++){
        int u = minDistance(dist , visited);
        visited[u] = 1;

        for(int v=0; v<V; v++){
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist);
}

int main(){
    int graph[V][V] ={
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };
    int source = 0;
    dijktras(graph,source);
    return 0;
}