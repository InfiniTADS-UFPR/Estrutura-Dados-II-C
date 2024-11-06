#include <stdlib.h>
#include <stdio.h>

int main(void){
    int vetor[10] = {23,36,76,12,98,56,35,75,97,2};
    int aux, maior, i, j, pos;

    for(i=0; i < 10; i++){
        maior=-10000;
        for(j=0; j < 10-i; j++){
            if(vetor[j] > maior){
                maior=vetor[j];
                pos=j;
            }
        }
        j--;
        aux = vetor[j];
        vetor[j] = vetor[pos];
        vetor[pos] = aux;
    }

    for (int i=0; i < 10; i++){
        printf("%d, ", vetor[i]);
    }
}