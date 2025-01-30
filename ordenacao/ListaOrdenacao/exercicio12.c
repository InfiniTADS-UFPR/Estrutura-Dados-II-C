#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(char *vetor, int tamanho){
    for (int i = 0; i < tamanho - 1; i++){
        for (int j = 0; j < tamanho - i - 1; j++){
            if (vetor[j] > vetor[j + 1]){
                char aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main(int argc, char *argv[]){
    char *vetor = argv[1];

    bubbleSort(vetor, strlen(vetor));

    printf("Palavra ordenada: %s\n", vetor);
}