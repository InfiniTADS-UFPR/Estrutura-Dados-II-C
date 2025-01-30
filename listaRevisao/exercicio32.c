// Prof Lucas - Lista de Revisão ED I
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

void insertEndCircularDoubly(DNode **head, int data) {
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = data;
    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        DNode *last = (*head)->prev;
        while(last->next != *head){
            last = last->next;
        }
        last->next=newNode;
        newNode->next = *head;
        newNode->prev=last;
        (*head)->prev = newNode;
    }
}