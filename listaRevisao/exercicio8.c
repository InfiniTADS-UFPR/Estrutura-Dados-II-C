#include <stdlib.h>
#include <stdio.h>

int main(void){
    int vetor[100], valor, pos=-1;

    for(int i=0; i<100; i++){
        vetor[i] = i+1;

    }

    valor = rand()%100;

    printf("Valor para ser pesquisado: %d\n", valor);

    for(int i=0;i<100;i++){
        if(vetor[i]==valor){
            pos = i;
        }
    }

    if (pos == -1){
        printf("Valor nao encontrado no vetor\n");
    } else{
        printf("Valor encontrado em: vetor[%d]\n", pos);
    }
}