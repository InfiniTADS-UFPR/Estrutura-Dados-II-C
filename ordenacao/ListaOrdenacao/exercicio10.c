#include <stdio.h>
#include <stdlib.h>

float mergeCount = 0.0, quick = 0.0;

void printVetor(int *vetor, int inicio, int fim){
    printf("[ ");
    for(int i = inicio; i <= fim; i++){
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

void merge(int *vetor, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *) malloc(tamanho * sizeof(int));
    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(vetor[p1] < vetor[p2]){
                    temp[i] = vetor[p1++];
                }else{
                    temp[i] = vetor[p2++];
                }
                if(p1 > meio) fim1 = 1;
                if(p2 > fim) fim2 = 1;
            }else{
                if(!fim1){
                    temp[i] = vetor[p1++];
                }else{
                    temp[i] = vetor[p2++];
                }
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++, k++){
            vetor[k] = temp[j];
        }
    }
    free(temp);
}

void mergeSort(int *vetor, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void quickSort(int *vetor, int inicio, int fim){
    int pivo, aux, i, j, meio;
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

int main(void){
    int vetor1[16] = {3,4,9,2,5,8,2,1,7,4,6,2,9,8,5,1};
    int vetor2[16] = {3,4,9,2,5,8,2,1,7,4,6,2,9,8,5,1};

    printf("Merge Sort\n");
    mergeSort(vetor1, 0, 15);

    printf("Quick Sort\n");
    quickSort(vetor2, 0, 15);
}