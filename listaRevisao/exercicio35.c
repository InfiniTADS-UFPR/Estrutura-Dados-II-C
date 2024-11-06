// Prof Lucas - Lista de Revisão ED I
#include <stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

void pushDynamic(StackNode **top, int data) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}