#include <stdlib.h>
#include <stdio.h>

int main(void){
    int vetor[10] = {23,36,76,12,98,56,35,75,97,2};
    int aux, i=0, j=1;

    while(j < 10){
        aux = vetor[j];
        i=j-1;
        while((i>=0) && (vetor[i]>aux)){
            vetor[i+1] = vetor[i];
            i--;
        }
        vetor[i+1]=aux;
        j++;
    }

    for (int i=0; i < 10; i++){
        printf("%d, ", vetor[i]);
    }
}