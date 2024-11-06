#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
    struct No *prev;
} no;

void add(no **lista, int valor, int opt){
    no *primeiro = *lista;
    no *item = (no*)malloc(sizeof(no));
    item->valor = valor;

    if(*lista == NULL){
        *lista = item;
        item->prox = item;
        item->prev = item;
        printf("Inserindo primeiro elemento...\n");
    } else{
        no *aux = *lista;
        while(aux->prox != *lista){
            aux = aux->prox;
        }
        aux->prox=item;
        item->prox = primeiro;
        item->prev=aux;
        primeiro->prev = item;
        if(opt == 1){
            printf("Inserindo no final...\n");
        } else{
            printf("Inserindo no inicio...\n");
            *lista = item;
        }
    }
}

void del(no **lista, int opt){
    no *aux = *lista;
    no *primeiro = *lista;

    if(opt == 1){
        while(aux->prox != *lista)
            aux = aux->prox;
        aux->prox->prev = aux->prev;
        aux->prev->prox = aux->prox;
        printf("Removendo o elemento %d do fim...\n", aux->valor);
        free(aux);
    } else{
        primeiro->prox->prev = primeiro->prev;
        primeiro->prev->prox = primeiro->prox;
        *lista = primeiro->prox;
        printf("Removendo o elemento %d do inicio...\n", primeiro->valor);
        free(primeiro);
    }
}

void mostraLista(no* lista){
    no *aux = lista;
    if (aux != NULL){
        while(aux->prox != lista){
            printf("%d, ", aux->valor);
            aux = aux->prox;
        }
        printf("%d", aux->valor);
    }
    printf("\n");
}

int main(void){
    no *vetor;

    for (int i = 0; i < 5; i++){
        int input;
        printf("Digite um valor numerico: ");
        scanf("%d", &input);
        add(&vetor, input, 1);
    }
    mostraLista(vetor);
    del(&vetor, 1);
    del(&vetor, 2);
    mostraLista(vetor);
    for (int i = 0; i < 8; i++){
        int input;
        printf("Digite um valor numerico: ");
        scanf("%d", &input);
        add(&vetor, input, 2);
    }
    mostraLista(vetor);
}