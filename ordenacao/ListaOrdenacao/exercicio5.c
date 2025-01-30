#include <stdio.h>

void ordenacaoDesc(char *vetor[], int tamanho){
  for (int i = 1; i < tamanho - 1; i++){
    for (int j = i + 1; j < tamanho; j++){
      if (*vetor[i] < *vetor[j]){
        char aux = *vetor[i];
        *vetor[i] = *vetor[j];
        *vetor[j] = aux;
      }
    }
  }
}

void printVetor(char *vetor[], int tamanho){
  printf("Vetor: [");
  for (int i = 1; i < tamanho - 1; i++){
    printf("%c, ", *vetor[i]);
  }
  printf("%c]\n", *vetor[tamanho - 1]);
}

int main(int argc, char *argv[]){
  printVetor(argv, argc);
  ordenacaoDesc(argv, argc);
  printVetor(argv, argc);

  return 0;
}
