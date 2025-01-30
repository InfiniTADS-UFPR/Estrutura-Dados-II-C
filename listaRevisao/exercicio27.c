#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
    struct No *prev;
} no;

struct Header{
    int tamanho;
    no *primeiro;
    no *ultimo;
} *head;

void init(){
    head = (struct Header*)malloc(sizeof(struct Header));
    head->tamanho=0;
    head->primeiro=NULL;
    head->ultimo=NULL;
}

void add(int valor, int opt){
    no *item = (no*)malloc(sizeof(no));
    item->valor = valor;

    if(head->primeiro == NULL){
        head->primeiro = item;
        head->ultimo = item;
        item->prox = item;
        item->prev = item;
        printf("Inserindo primeiro elemento...\n");
    } else{
        head->ultimo->prox=item;
        item->prox = head->primeiro;
        item->prev=head->ultimo;
        head->primeiro->prev = item;
        if(opt == 1){
            printf("Inserindo no final...\n");
            head->ultimo = item;
        } else{
            printf("Inserindo no inicio...\n");
            head->primeiro = item;
        }
    }
    head->tamanho++;
}

void del(int opt){

    if(opt == 1){
        no *aux = head->ultimo;
        head->primeiro->prev = aux->prev;
        aux->prev->prox = head->primeiro;
        head->ultimo = aux->prev;
        printf("Removendo o elemento %d do fim...\n", aux->valor);
        free(aux);
    } else{
        no *aux = head->primeiro;
        aux->prox->prev = head->ultimo;
        head->ultimo->prox = aux->prox;
        head->primeiro = aux->prox;
        printf("Removendo o elemento %d do inicio...\n", aux->valor);
        free(aux);
    }
    head->tamanho--;
}

void mostraLista(int opt){
    no *aux = (opt == 1) ? head->primeiro : head->ultimo;
    if (aux != NULL){
        printf("Tamanho da lista: %d\n", head->tamanho);
        for(int i = 0; i < head->tamanho-1; i++){
            printf("%d, ", aux->valor);
            aux = (opt == 1) ? aux->prox : aux->prev;
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
        add(input, 1);
    }
    mostraLista(1);
    del(1);
    del(2);
    mostraLista(1);
    for (int i = 0; i < 8; i++){
        int input;
        printf("Digite um valor numerico: ");
        scanf("%d", &input);
        add(input, 2);
    }
    mostraLista(1);
    mostraLista(2);
}