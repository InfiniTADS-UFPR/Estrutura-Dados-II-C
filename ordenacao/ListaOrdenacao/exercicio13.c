#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(char *vetor[], int tamanho){
  for (int i=1;i<tamanho;i++){
    int min = i;
    for(int j=i;j<tamanho;j++){
      if(strcmp(vetor[j],vetor[min]) < 0){
        min = j;
      }
    }
    if(min != i){
      char *aux = (char *)malloc((strlen(vetor[i])+1) * sizeof(char));
      strcpy(aux, vetor[i]);
      vetor[i] = (char *)malloc((strlen(vetor[min])+1) * sizeof(char));
      strcpy(vetor[i], vetor[min]);
      vetor[min] = (char *)malloc((strlen(aux)+1) * sizeof(char));
      strcpy(vetor[min], aux);
      free(aux);
    }
  }
}

int main(int argc, char *argv[]){

    selectionSort(argv,argc);
    
    for(int i=1;i<argc;i++){
        printf("%s\n",argv[i]);
    }

    return 0;
}