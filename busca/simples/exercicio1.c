#include <stdio.h>
#include <stdlib.h>

int buscaSimples(int valor, int vetor[], int len){
    for(int i=0;i<len;i++){
        if(vetor[i]==valor){
            return i;
        }
    }
    return -1;
}

int main(void){
    int vetor[5] = {4, 2, 7, 1, 3};

    int pos = buscaSimples(3, vetor, 5);
    if (pos == -1){
        printf("Elemento n encontrado no vetor\n");
    } else{
        printf("Elemento encontrado em vetor[%d]\n", pos);
    }
}