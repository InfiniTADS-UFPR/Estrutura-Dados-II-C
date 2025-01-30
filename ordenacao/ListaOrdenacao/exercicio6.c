#include <stdio.h>
#include <stdlib.h>

void printVetor(char *vetor[], int tamanho){
  printf("Vetor: [");
    for (int i = 1; i < tamanho-1; i++){
        printf("%c, ", *vetor[i]);
    }
    printf("%c]\n", *vetor[tamanho-1]);
}

char* addOrdenado(char *vetor[], int tamanho, char novo){
  char* vetornovo = (char *)malloc((tamanho+1)*sizeof(char));

  for (int i = 1; i < tamanho; i++){
    vetornovo[i-1] = *vetor[i];
  }
  vetornovo[tamanho-1] = novo;

  for (int i = 0; i < tamanho; i++){
    for (int j = i + 1; j < tamanho; j++){
      if (vetornovo[i] > vetornovo[j]){
        char aux = vetornovo[i];
        vetornovo[i] = vetornovo[j];
        vetornovo[j] = aux;
      }
    }
  }  

  return vetornovo;
}

int main(int argc, char *argv[]){
  char novo;

  printVetor(argv, argc);
  printf("Digite um novo valor: ");
  scanf("%c", &novo);

  char* vetorNovo = addOrdenado(argv, argc, novo);

  printf("Vetor ordenado: [");
  for (int i = 0; i < argc-1; i++){
    printf("%c, ", vetorNovo[i]);
  }
  printf("%c]\n", vetorNovo[argc-1]);

  free(vetorNovo);
  return 0;
}
