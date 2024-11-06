// Prof Lucas - Lista de Revisão ED I
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void removeFirst(Node **head) {
    if (*head == NULL)
        return;
    Node *temp = *head;
    Node *last = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }
    while (last->next != head){
        last = last->next;
    }
    last->next = temp->next;
    head = temp->next;
    free(temp);
}