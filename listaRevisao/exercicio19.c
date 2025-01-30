#include <stdlib.h>
#include <stdio.h>

int pesquisaBinaria(int valor, int inicio, int fim, int vetor[]){
    int aux = (fim-inicio)/2 + inicio;
    if(aux==inicio||aux==fim) return -1;
    if(vetor[aux]==valor) return aux;
    if(vetor[aux]>valor) return pesquisaBinaria(valor, inicio, aux, vetor);
    if(vetor[aux]<valor) return pesquisaBinaria(valor, aux, fim, vetor);
}

int main(void){
    int vetor[100], valor, pos;

    for(int i=0; i<100; i++){
        vetor[i] = i+1;

    }

    valor = rand()%100;

    printf("Valor para ser pesquisado: %d\n", valor);

    pos = pesquisaBinaria(valor, 0, 100, vetor);

    if (pos == -1){
        printf("Valor nao encontrado no vetor\n");
    } else{
        printf("Valor encontrado em: vetor[%d]\n", pos);
    }
}