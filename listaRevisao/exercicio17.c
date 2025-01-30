#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *prox;
} *pilha;

struct No* criarNo(int valor){
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->valor=valor;
    novo->prox=NULL;
    return novo;
};

void push(struct No* no){
    if(pilha == NULL){
        pilha = no;
    } else{
        struct No *aux = pilha;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox=no;
    }
}

void pop(){
    struct No *aux = pilha;
    struct No *anterior=NULL;
    while(aux->prox != NULL){
        anterior=aux;
        aux = aux->prox;
    }
    if(anterior==NULL){
        pilha=NULL;
    } else{
        anterior->prox=NULL;
    }
    printf("Removendo o elemento %d da pilha...\n", aux->valor);
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
        push(criarNo(v));
        printf("Pilha: "); mostraLista(pilha);
    }
    for (int y=0; y < 5; y++){
        pop();
        printf("Pilha: "); mostraLista(pilha);
    }
    
    
    return 0;
}