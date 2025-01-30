#include <stdio.h>
#include <stdlib.h>

//É o mesmo código do 5... mas se parar para pensar, ela já é meio circular pq eu marco o inicio e o fim.
//Se quiser dá para fazer ele dar a volta... mas eu não entendi a necessidade.

struct Fila{
    int fila[5];
    int inicio, fim;
} fila;

void inicializa(){
    fila.inicio = 0;
    fila.fim = -1;
}

void push(int valor){
    if(fila.fim < 4){
        fila.fim++;
        fila.fila[fila.fim] = valor;
    } else{
        printf("Fila cheia!\n");
    }
}

void pop(){
    if(fila.fim == -1){
        printf("Fila vazia!\n");
    } else{
        printf("Removendo o elemento %d da fila...\n", fila.fila[fila.inicio]);
        for (int i = 0; i < fila.fim; i++){
         fila.fila[i] = fila.fila[i+1];   
        }
        fila.fila[fila.fim] = 0;
        fila.fim--;
    }
}

void mostraLista(struct Fila fila){
    for (int i = 0; i < 5; i++){
        printf("%d ", fila.fila[i]);
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
        printf("Fila: "); mostraLista(fila);
    }
    for (int y=0; y < 5; y++){
        pop();
        printf("Fila: "); mostraLista(fila);
    }
    
    return 0;
}