// Prof Lucas - Lista de Revisão ED I
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertEnd(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node *temp = *head;
        while (temp->next != *head){
            temp = temp->next;
        }
        temp->next=newNode;
        newNode->next = *head;
    }
}
