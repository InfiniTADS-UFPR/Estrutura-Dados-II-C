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
    int vetor[4] = {10,20,30,40};

    int pos = buscaBinaria(25, 0, 4, vetor);
    if (pos == -1){
        printf("Elemento nao encontrado no vetor\n");
    } else{
        printf("Elemento encontrado em vetor[%d]\n", pos);
    }
}