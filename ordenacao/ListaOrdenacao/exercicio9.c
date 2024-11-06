#include <stdio.h>
#include <stdlib.h>

void insertionSort(int vetor[], int tamanho){
    int contador = 0;
    for (int i = 1; i < tamanho; i++){
        int aux = vetor[i];
        int j = i - 1;
        while(j >= 0 && aux < vetor[j]){
            vetor[j+1] = vetor[j];
            j--;
            contador++;
        }
        vetor[j+1] = aux;
    }
    printf("Número de comparações: %d\n", contador);
}

int main(void){
    int vetor[10] = {72, 12, 62, 69, 27, 67, 41, 56, 33, 74};
    insertionSort(vetor, 10);
    for (int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}