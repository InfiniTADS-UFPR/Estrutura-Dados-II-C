// Prof Lucas - Lista de Revisão ED I
#include <stdlib.h>
#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int data) {
    if (s->top < MAX - 1) {
        s->top++;
        s->arr[s->top] = data;
    }
}
