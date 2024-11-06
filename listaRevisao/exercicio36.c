// Prof Lucas - Lista de Revisão ED I
#include <stdlib.h>
#define MAX 10

typedef struct Queue {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}
void enqueue(Queue *q, int data) {
    if (q->rear < MAX - 1) {
        q->rear++;
        q->arr[q->rear] = data;
    }
}