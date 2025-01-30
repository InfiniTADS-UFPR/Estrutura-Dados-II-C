#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *fp;
    char palavra[10];

    if (!(fp = fopen("arquivo.txt", "a"))){
        printf("Falha ao abrir o arquivo no modo escrita!");
        exit(1);
    }

    fprintf(fp, "Hello World, from File!");
    printf("Digite uma palavra (sem space) para inserir no arquivo: ");
    scanf("%s", palavra);
    fprintf(fp, "\nPalavra: %s", palavra);
    fclose(fp);

    if (!(fp = fopen("arquivo.txt", "r"))){
        printf("Falha ao abrir o arquivo no modo leitura!");
        exit(1);
    }

    while(!feof(fp)){
        char linha[30];
        fgets(linha, 30, fp);
        printf("%s", linha);
    }
    printf("\n");
    fclose(fp);

    return 0;
}