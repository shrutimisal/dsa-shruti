#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue* q) {
    return q->r == q->f;
}

int isFull(struct queue* q) {
    return q->r == q->size - 1;
}

void enqueue(struct queue* q, int val) {
    if (!isFull(q)) {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue* q) {
    if (!isEmpty(q)) {
        q->f++;
        return q->arr[q->f];
    }
    return -1;
}

//BFS FUNCTION
void BFS(int a[4][4], int start) {
    int visited[4] = {0};

    struct queue q;
    q.size = 50;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    printf("%d ", start);
    visited[start] = 1;
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        for (int j = 0; j < 4; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
}

int main() {
    // int a[7][7] = {
    //     {0,1,1,1,0,0,0},
    //     {1,0,1,0,0,0,0},
    //     {1,1,0,1,1,0,0},
    //     {1,0,1,0,1,0,0},
    //     {0,0,1,1,0,1,1},
    //     {0,0,0,0,1,0,0},
    //     {0,0,0,0,1,0,0}
    // };

    int a[4][4] = {
    {0,1,1,0},
    {1,0,0,1},
    {1,0,0,1},
    {0,1,1,0}
};


    printf("BFS Traversal: ");
    BFS(a, 0);

    return 0;
}
