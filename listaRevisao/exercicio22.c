#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int pesquisaSequencial(int valor, int vetor[], int len){
    for(int i=0;i<len;i++){
        if(vetor[i]==valor){
            return i;
        }
    }
    return -1;
}

int pesquisaBinaria(int valor, int inicio, int fim, int vetor[]){
    int aux = (fim-inicio)/2 + inicio;
    if(aux==inicio||aux==fim) return -1;
    if(vetor[aux]==valor) return aux;
    if(vetor[aux]>valor) return pesquisaBinaria(valor, inicio, aux, vetor);
    if(vetor[aux]<valor) return pesquisaBinaria(valor, aux, fim, vetor);
}

int main(void){

    for(int i=0;i<5;i++){
        printf("Caso teste %d:\n", i+1);
        int len = rand()%1000000;
        int vetor[len];
        printf("Tamanho do vetor %d: \n", len);
        for(int j=0; j<len; j++){
            vetor[j] = j+1;
        }

        int valor = rand()%len;
        printf("Valor pesquisado: %d\n", valor);

        clock_t t0S = clock();
        printf("Pesquisa sequencial retornou: vetor[%d] ",  pesquisaSequencial(valor, vetor, len));
        clock_t t1S = clock();
        double tempoS = (((double) (t1S - t0S)) / CLOCKS_PER_SEC)*1000;
        printf("em tempo %.4f milissegundos\n", tempoS);

        clock_t t0B = clock();
        printf("Pesquisa binaria retornou: vetor[%d] ",  pesquisaBinaria(valor, 0, len, vetor));
        clock_t t1B = clock();
        double tempoB = (((double) (t1B - t0B)) / CLOCKS_PER_SEC)*1000;
        printf("em tempo %.4f milissegundos\n", tempoB);

        printf("\n-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-\n");
    }

}