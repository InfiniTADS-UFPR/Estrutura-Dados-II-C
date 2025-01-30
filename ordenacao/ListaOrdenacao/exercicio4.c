#include <stdio.h>

void checkOrdenacao(char *vetor[], int tamanho){
    int i;
    for (i = 1; i < tamanho - 1; i++){
        if (*vetor[i] > *vetor[i + 1]){
            printf("Não ordenado.\n");
            return;
        }
    }
    printf("Ordenado.\n");
    return;
}

int main(int argc, char *argv[]){
    printf("Vetor lido: [");
    for (int i = 1; i < argc-1; i++){
        printf("%c, ", *argv[i]);
    }
    printf("%c]\n", *argv[argc-1]);
    checkOrdenacao(argv, argc);
    return 0;
}
