#include <stdio.h>
#include <stdlib.h>

int buscaSimples(int valor, int vetor[], int len){
    if (len == 0) return -1;
    for(int i=0;i<len;i++){
        if(vetor[i]==valor){
            return i;
        }
    }
    return -1;
}

int main(void){
    int vetor[5];

    int pos = buscaSimples(10, vetor, 0);
    if (pos == -1){
        printf("Elemento nao encontrado no vetor\n");
    } else{
        printf("Elemento encontrado em vetor[%d]\n", pos);
    }
}