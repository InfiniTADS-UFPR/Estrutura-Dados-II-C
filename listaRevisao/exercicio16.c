#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
} no;

struct Header{
    int tamanho;
    no *primeiro;
} *head;

void init(){
    head = (struct Header*)malloc(sizeof(struct Header));
    head->tamanho=0;
    head->primeiro=NULL;
}

void add(int valor){
    no *item = (no*)malloc(sizeof(no));
    item->valor = valor;
    item->prox = NULL;

    if(head->primeiro == NULL){
        head->primeiro = item;
    } else{
        no *aux = head->primeiro;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox=item;
    }
    head->tamanho++;
}

void del(){
    struct No *aux = head->primeiro;
    struct No *anterior=NULL;
    for(int i = 0; i < head->tamanho-1; i++){
        anterior=aux;
        aux = aux->prox;
    }
    if(anterior==NULL){
        head->primeiro=NULL;
    } else{
        anterior->prox=NULL;
    }
    printf("Removendo o elemento %d da lista...\n", aux->valor);
    head->tamanho--;
    free(aux);
}

void mostraLista(){
    no *aux = head->primeiro;
    if (aux != NULL){
        printf("Tamanho da lista: %d\n", head->tamanho);
        for(int i = 0; i < head->tamanho-1; i++){
            printf("%d, ", aux->valor);
            aux = aux->prox;
        }
        printf("%d", aux->valor);
    }
    printf("\n");
}

int main(void){
    init();
    for (int i = 0; i < 5; i++){
        int input;
        printf("Digite um valor numerico: ");
        scanf("%d", &input);
        add(input);
    }
    mostraLista();
    del();
    del();
    mostraLista();
    for (int i = 0; i < 8; i++){
        int input;
        printf("Digite um valor numerico: ");
        scanf("%d", &input);
        add(input);
    }
    mostraLista();
}