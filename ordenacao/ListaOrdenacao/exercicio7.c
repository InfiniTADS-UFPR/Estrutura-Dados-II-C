#include <stdio.h>
#include <string.h>

int checkOrdenacao(char *vetor[], int tamanho){
    int i;
    for (i = 1; i < tamanho - 1; i++){
        if (*vetor[i] > *vetor[i + 1]){
            return -1;
        }
    }
    return 0;
}

void insertionSort(char *vetor[], int tamanho){
    for (int i = 2; i < tamanho; i++){
        char *aux = vetor[i];
        int j = i - 1;
        while(j >= 1 && *aux < *vetor[j]){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;
    }
}

int buscaBinaria(char valor[], int inicio, int fim, char *vetor[]){
    int aux = (fim-inicio)/2 + inicio;
    int raz = strcmp(vetor[aux], valor);
    if(raz == 0) return aux;
    if(aux==inicio||aux==fim) return -1;
    if(raz > 0) return buscaBinaria(valor, inicio, aux, vetor);
    if(raz < 0) return buscaBinaria(valor, aux, fim, vetor);
}

void printVetor(char *vetor[], int tamanho){
  printf("Vetor: [");
    for (int i = 1; i < tamanho-1; i++){
        printf("%c, ", *vetor[i]);
    }
    printf("%c]\n", *vetor[tamanho-1]);
}

int main(int argc, char *argv[]){

    if(checkOrdenacao(argv, argc) != 0){
        insertionSort(argv, argc);
    }

    printVetor(argv, argc);

    char valor;
    printf("Digite um valor a ser buscado: ");
    scanf("%c", &valor);

    int pos = buscaBinaria(&valor, 1, argc, argv);

    if(pos == -1){
        printf("Valor não encontrado.\n");
    }else{
        printf("Valor encontrado na posição %d.\n", pos);
    }

  return 0;
}
