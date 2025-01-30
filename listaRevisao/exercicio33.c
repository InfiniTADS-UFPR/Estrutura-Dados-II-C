// Prof Lucas - Lista de Revisão ED I
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct HeaderNode {
    int size;
    Node *next;
} HeaderNode;

HeaderNode *createList() {
    HeaderNode *header = (HeaderNode *)malloc(sizeof(HeaderNode));
    header->size = 0;
    header->next = NULL;
    return header;
}

void insertWithHeader(HeaderNode *header, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = header->next;
    Node *temp = header->next;
    if(temp != NULL){
        for(int i=0;i<header->size-1;i++)
            temp = temp->next;
        temp->next = newNode;
    } else{
        header->next=newNode;
    }
    header->size++;
}