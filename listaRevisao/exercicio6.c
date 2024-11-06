#include <stdio.h>
#include <stdlib.h>

struct Pilha{
    int pilha[5];
    int topo;
} pilha;

void inicializa(){
    pilha.topo = -1;
}

void push(int valor){
    if(pilha.topo < 4){
        pilha.topo++;
        pilha.pilha[pilha.topo] = valor;
    } else{
        printf("Pilha cheia!\n");
    }
}

void pop(){
    if(pilha.topo == -1){
        printf("Pilha vazia!\n");
    } else{
        printf("Removendo o elemento %d da pilha...\n", pilha.pilha[pilha.topo]);
        pilha.pilha[pilha.topo] = 0;
        pilha.topo--;
    }
}

void mostraLista(struct Pilha pilha){
    for (int i = 0; i < 5; i++){
        printf("%d ", pilha.pilha[i]);
    }
    printf("\n");
}

int main(void){
    int v;
    inicializa();
    
    for(int x=0; x < 5; x++){
        printf("Digite um valor para inserir: ");
        scanf("%d", &v);
        push(v);
        printf("Pilha: "); mostraLista(pilha);
    }
    for (int y=0; y < 5; y++){
        pop();
        printf("Pilha: "); mostraLista(pilha);
    }
    
    return 0;
}