#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
} no;

void add(no **lista, int valor){
    no *item = (no*)malloc(sizeof(no));
    item->valor = valor;

    if(*lista == NULL){
        *lista = item;
        item->prox = item;
    } else{
        no *aux = *lista;
        while(aux->prox != *lista){
            aux = aux->prox;
        }
        aux->prox=item;
        item->prox = *lista;
    }
}

void del(no **lista){
    no *aux = *lista;
    no *anterior=NULL;
    while(aux->prox != *lista){
        anterior=aux;
        aux = aux->prox;
    }
    if(anterior==NULL){
        *lista=NULL;
    } else{
        anterior->prox= *lista;
    }
    printf("Removendo o elemento %d da lista...\n", aux->valor);
    free(aux);
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
        add(&vetor, input);
    }
    mostraLista(vetor);
    del(&vetor);
    del(&vetor);
    mostraLista(vetor);
    for (int i = 0; i < 8; i++){
        int input;
        printf("Digite um valor numerico: ");
        scanf("%d", &input);
        add(&vetor, input);
    }
    mostraLista(vetor);
}