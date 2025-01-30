// Prof Lucas - Lista de Revisão ED I
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

void removeLast(DNode **head) {
    if (*head == NULL)
        return;
    DNode *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    } else {
        *head = NULL;
    }
    free(temp);
}