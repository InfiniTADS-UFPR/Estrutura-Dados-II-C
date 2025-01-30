#include <stdlib.h>
#include <stdio.h>

int main(void){
    int vetor[10] = {23,36,76,12,98,56,35,75,97,2};
    int aux;

    for(int i=0; i < 10; i++){
        for(int j=0; j < 10; j++){
            if(vetor[i] < vetor[j]){
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
    }

    for (int i=0; i < 10; i++){
        printf("%d, ", vetor[i]);
    }
}