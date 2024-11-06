#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quickSort(char *vetor, int inicio, int fim){
    char pivo, aux;
    int i, j, meio;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2);
    pivo = vetor[meio];
    do{
        while(vetor[i] < pivo) i++;
        while(vetor[j] > pivo) j--;
        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }while(j > i);
    if(inicio < j) quickSort(vetor, inicio, j);
    if(i < fim) quickSort(vetor, i, fim);
}

int main(int argc, char *argv[]){
    char *vetor = argv[1];

    quickSort(vetor, 0, strlen(vetor)-1);

    printf("Palavra ordenada: %s\n", vetor);
}