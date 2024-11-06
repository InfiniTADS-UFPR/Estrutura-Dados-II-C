#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int valor, int inicio, int fim, int vetor[]){
    int aux = (fim-inicio)/2 + inicio;
    if(aux==inicio||aux==fim) return -1;
    if(vetor[aux]==valor) return aux;
    if(vetor[aux]>valor) return buscaBinaria(valor, inicio, aux, vetor);
    if(vetor[aux]<valor) return buscaBinaria(valor, aux, fim, vetor);
}

int main(void){
    int vetor[1000];
    int len = 1000;

    for(int j=0; j<len; j++){
        vetor[j] = j+1;
    }

    int pos = buscaBinaria(500, 0, len, vetor);
    if (pos == -1){
        printf("Elemento %d nao encontrado no vetor\n", 500);
    } else{
        printf("Elemento %d encontrado em vetor[%d]\n", 500, pos);
    }
    pos = buscaBinaria(2000, 0, len, vetor);
    if (pos == -1){
        printf("Elemento %d nao encontrado no vetor\n", 2000);
    } else{
        printf("Elemento %d encontrado em vetor[%d]\n", 2000, pos);
    }
}