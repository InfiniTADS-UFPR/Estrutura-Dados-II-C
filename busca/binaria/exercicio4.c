#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(float valor, int inicio, int fim, float vetor[]){
    int aux = (fim-inicio)/2 + inicio;
    if(aux==inicio||aux==fim) return -1;
    if(vetor[aux]==valor) return aux;
    if(vetor[aux]>valor) return buscaBinaria(valor, inicio, aux, vetor);
    if(vetor[aux]<valor) return buscaBinaria(valor, aux, fim, vetor);
}

int main(void){
    float vetor[4] = {0.5, 1.5, 2.5, 3.5};

    int pos = buscaBinaria(2.5, 0, 4, vetor);
    if (pos == -1){
        printf("Elemento n encontrado no vetor\n");
    } else{
        printf("Elemento encontrado em vetor[%d]\n", pos);
    }
}