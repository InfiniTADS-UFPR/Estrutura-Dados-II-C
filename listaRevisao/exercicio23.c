#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void ordenaBubble(int vetor[], int len){
    int aux;

    for(int i=0; i < len; i++){
        for(int j=0; j < len; j++){
            if(vetor[i] < vetor[j]){
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
    }
}

void ordenaSelection(int vetor[], int len){
    int aux, maior, i, j, pos;

    for(i=0; i < len; i++){
        maior=-1000;
        for(j=0; j < len-i; j++){
            if(vetor[j] > maior){
                maior=vetor[j];
                pos=j;
            }
        }
        j--;
        aux = vetor[j];
        vetor[j] = vetor[pos];
        vetor[pos] = aux;
    }
}

void ordenaInsertion(int vetor[], int len){
    int aux, i=0, j=1;

    while(j < len){
        aux = vetor[j];
        i=j-1;
        while((i>=0) && (vetor[i]>aux)){
            vetor[i+1] = vetor[i];
            i--;
        }
        vetor[i+1]=aux;
        j++;
    }
}

int main(void){

    for(int i=0;i<5;i++){
        printf("Caso teste %d:\n", i+1);
        int len = rand()%500000;
        int vetor1[len], vetor2[len], vetor3[len];
        printf("Tamanho do vetor %d: \n", len);
        for(int j=0; j<len; j++){
            int entrada = rand()%2000;
            vetor1[j] = entrada;
            vetor2[j] = entrada; 
            vetor3[j] = entrada; 
        }

        printf("Ordenação Insertion... \n");
        clock_t t0I = clock();
        ordenaInsertion(vetor3, len);
        clock_t t1I = clock();
        double tempoI = (((double) (t1I - t0I)) / CLOCKS_PER_SEC);

        printf("Ordenação Selection... \n");
        clock_t t0S = clock();
        ordenaSelection(vetor2, len);
        clock_t t1S = clock();
        double tempoS = (((double) (t1S - t0S)) / CLOCKS_PER_SEC);

        printf("Ordenação bubble... \n");
        clock_t t0B = clock();
        ordenaBubble(vetor1, len);
        clock_t t1B = clock();
        double tempoB = (((double) (t1B - t0B)) / CLOCKS_PER_SEC);

        printf("BubbleSort terminou em %.4f segundos\n", tempoB);
        printf("SelectionSort terminou em %.4f segundos\n", tempoS);
        printf("InsertionSort terminou em %.4f segundos\n", tempoI);

        printf("\n-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-\n");
    }

}