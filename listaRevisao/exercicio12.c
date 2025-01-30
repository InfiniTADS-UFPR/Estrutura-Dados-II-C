#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
    struct No *prev;
} no;

void add(no **lista, int valor, int opt){
    no *item = (no*)malloc(sizeof(no));
    item->valor = valor;
    item->prox = NULL;
    item->prev = NULL;

    if(*lista == NULL){
        *lista = item;
    } else if(opt == 1){
        no *aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox=item;
        item->prev=aux;
        printf("Inserindo no fim...\n");
    } else{
        item->prox = *lista;
        *lista = item;
        printf("Inserindo no inicio...\n");
    }

}

void del(no **lista, int opt){
    no *aux = *lista;

    if(opt == 1){
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        if(aux->prev==NULL){
            *lista=NULL;
        } else{
            aux->prev->prox=NULL;
        }
        printf("Removendo o elemento %d do fim...\n", aux->valor);
    } else{
        if(aux->prox != NULL){
            aux->prox->prev=NULL;
        }
        *lista = aux->prox;
        printf("Removendo o elemento %d do inicio...\n", aux->valor);
    }
    free(aux);
}

void mostraLista(no* lista){
    no *aux = lista;
    if (aux != NULL){
        while(aux->prox != NULL){
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