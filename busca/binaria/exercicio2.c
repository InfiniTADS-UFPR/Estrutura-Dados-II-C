#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaBinaria(char valor[], int inicio, int fim, char *vetor[]){
    int aux = (fim-inicio)/2 + inicio;
    if(aux==inicio||aux==fim) return -1;
    int raz = strcmp(vetor[aux], valor);
    if(raz == 0) return aux;
    if(raz > 0) return buscaBinaria(valor, inicio, aux, vetor);
    if(raz < 0) return buscaBinaria(valor, aux, fim, vetor);
}

int main(void){
    char *vetor[4] = {"abacaxi", "banana", "laranja", "maça"};

    int pos = buscaBinaria("maça", 0, 4, vetor);
    if (pos == -1){
        printf("Elemento n encontrado no vetor\n");
    } else{
        printf("Elemento encontrado em vetor[%d]\n", pos);
    }
}