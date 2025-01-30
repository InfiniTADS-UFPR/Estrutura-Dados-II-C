#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaSimples(char valor[], char *vetor[], int len){
    for(int i = 0; i < len; i++){
        if(strcmp(vetor[i], valor) == 0){
            return i;
        }
    }
    return -1;
}

int main(void){
    char *vetor[3] = {"maça", "banana", "laranja"};

    int pos = buscaSimples("banana", vetor, 3);
    if (pos == -1){
        printf("Elemento não encontrado no vetor\n");
    } else{
        printf("Elemento encontrado em vetor[%d]\n", pos);
    }
}
