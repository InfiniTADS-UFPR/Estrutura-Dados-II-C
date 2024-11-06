#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
} no;

void add(no **lista, int valor){
    no *item = (no*)malloc(sizeof(no));
    item->valor = valor;
    item->prox = NULL;

    if(*lista == NULL){
        *lista = item;
    } else{
        no *aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox=item;
    }
}

void del(no **lista){
    struct No *aux = *lista;
    struct No *anterior=NULL;
    while(aux->prox != NULL){
        anterior=aux;
        aux = aux->prox;
    }
    if(anterior==NULL){
        *lista=NULL;
    } else{
        anterior->prox=NULL;
    }
    printf("Removendo o elemento %d da lista...\n", aux->valor);
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