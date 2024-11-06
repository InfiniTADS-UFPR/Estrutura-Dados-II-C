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
    int vetor[5] = {1,3,5,7,9};

    int pos = buscaBinaria(5, 0, 5, vetor);
    if (pos == -1){
        printf("Elemento n encontrado no vetor\n");
    } else{
        printf("Elemento encontrado em vetor[%d]\n", pos);
    }
}