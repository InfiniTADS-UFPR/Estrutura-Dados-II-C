#include <stdio.h>
#include <stdlib.h>

typedef struct tda{
    int vetor[10];
    int fim;
} tda;

void init(tda *dado){
    dado->fim = -1;
}

void add(tda *dado, int valor){
    if(dado->fim < 9){
         dado->fim++;
         dado->vetor[ dado->fim] = valor;
    } else{
        printf("Estrutura cheia!\n");
    }
}

void del(tda *dado, int pos){
    for(int j=pos; j <  dado->fim; j++){
         dado->vetor[j] =  dado->vetor[j+1];
    }
     dado->fim--;
}

void mostrar(tda *dado){
    for(int j=0; j <= dado->fim; j++){
        printf("%d ",  dado->vetor[j]);
    }
    printf("\n");
}

int main(void){
    tda myTda;

    init(&myTda);

    for (int i = 0; i < 5; i++){
        int input;
        printf("Digite um valor numerico: ");
        scanf("%d", &input);
        add(&myTda, input);
    }
    mostrar(&myTda);
    printf("Deletando pos vetor[2]...\n");
    del(&myTda, 2);
    printf("Deletando pos vetor[4]...\n");
    del(&myTda, 4);
    mostrar(&myTda);
    for (int i = 0; i < 8; i++){
        int input;
        printf("Digite um valor numerico: ");
        scanf("%d", &input);
        add(&myTda, input);
    }
    mostrar(&myTda);
}