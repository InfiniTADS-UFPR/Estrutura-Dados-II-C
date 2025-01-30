// Prof Lucas - Lista de Revisão ED I
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

void insertFront(DNode **head, int data) {
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL) {
        DNode *temp = *head;
        DNode *first = *head;
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        first->prev=newNode;
        newNode->next=first;
    }
    *head = newNode;
}