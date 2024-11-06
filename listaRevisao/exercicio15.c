#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *prox;
} *fila;

struct No* criarNo(int valor){
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->valor=valor;
    novo->prox=NULL;
    return novo;
};

void add(struct No* no){
    if(fila == NULL){
        fila = no;
    } else{
        struct No *aux = fila;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox=no;
    }
}

void delete(){
    struct No *aux = fila;
    int valor;
    printf("Removendo o elemento %d da fila...\n", aux->valor);
    fila = fila->prox;
    free(aux);
}

void mostraLista(struct No* lista){
    struct No *aux = lista;
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
    int v;
    
    for(int x=0; x < 5; x++){
        printf("Digite um valor para inserir: ");
        scanf("%d", &v);
        add(criarNo(v));
        printf("Fila: "); mostraLista(fila);
    }
    for (int y=0; y < 5; y++){
        delete();
        printf("Fila: "); mostraLista(fila);
    }
    
    
    return 0;
}