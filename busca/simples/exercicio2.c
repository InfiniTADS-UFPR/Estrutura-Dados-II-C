#include <stdio.h>
#include <stdlib.h>

int buscaSimples(int valor, int vetor[], int len){
    int pos = -1, count = 0;
    for(int i=0;i<len;i++){
        if(vetor[i]==valor){
            pos = 1;
            count++;
        }
    }
    return pos, count;
}

int main(void){
    int vetor[5] = {5, 2, 5, 1, 3};

    int pos, count = buscaSimples(5, vetor, 5);
    if (pos == -1){
        printf("Elemento n encontrado no vetor\n");
    } else{
        printf("Elemento encontrado pela 1. vez em vetor[%d]\n", pos);
        printf("Elemento encontrado %d vezes\n", count);
    }
}
