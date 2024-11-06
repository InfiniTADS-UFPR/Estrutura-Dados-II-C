#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node{
    int matricula;
    char uf[3];
    char cidade[50];
    char categoria[15];
    float medias[5];
    struct node *prox;
} escola;

FILE *abreArquivo(char *arquivo, char *modo){
    FILE *fp;
    if (!(fp = fopen(arquivo, modo))){
        printf("Falha ao abrir o arquivo!");
        exit(1);
    }
    return fp;
}

void insereEscola(escola **lista, escola *escolaAux){
    escola *aux = *lista;
    if(*lista == NULL){
        *lista = escolaAux;
        escolaAux->prox = NULL;
    }else{
        escolaAux->prox = *lista;
        *lista = escolaAux;
    }
}

int leArquivo(escola **lista){
    printf("Lendo dados de escolas...\n");
    FILE *fp = abreArquivo("ordenacaoDadoEnem/DadosEnem.txt", "r");
    escola *escolaAux;
    int count = 0;
    while(!feof(fp)){
        escolaAux = (escola*)malloc(sizeof(escola));
        char linha[256];
        if (fgets(linha, sizeof(linha), fp) != NULL) {
            sscanf(linha, "%d;%[^;];%[^;];%[^;];%f;%f;%f;%f;%f", 
                   &escolaAux->matricula, 
                   escolaAux->uf, 
                   escolaAux->cidade, 
                   escolaAux->categoria, 
                   &escolaAux->medias[0], 
                   &escolaAux->medias[1], 
                   &escolaAux->medias[2], 
                   &escolaAux->medias[3], 
                   &escolaAux->medias[4]);
        }
        insereEscola(lista, escolaAux);
        count++;
    }
    fclose(fp);
    return count;
}

void printEscolas(escola *lista){
    escola *aux = lista;
    for(int i=0; aux != NULL && i < 15; i++){
        printf("Escola %d (%s - %s), Tipo %s; Médias: {'Ciências exatas': %.2f, 'Matemática': %.2f, 'Ciências humanas': %.2f, 'Linguagens': %.2f, 'Redação': %.2f}\n", 
        aux->matricula, aux->cidade, aux->uf, aux->categoria, aux->medias[0], aux->medias[1], aux->medias[2], aux->medias[3], aux->medias[4]);
        aux = aux->prox;
    }
}

escola* ordenacaoPorConteudo(escola *lista){
    escola *aux = lista;
    escola *aux2 = lista;
    escola *menor;
    while(aux != NULL){
        menor = aux;
        aux2 = aux->prox;
        while(aux2 != NULL){
            if(aux2->matricula < menor->matricula){
                menor = aux2;
            }
            aux2 = aux2->prox;
        }
        int matricula = aux->matricula;
        aux->matricula = menor->matricula;
        menor->matricula = matricula;
        char uf[3];
        strcpy(uf, aux->uf);
        strcpy(aux->uf, menor->uf);
        strcpy(menor->uf, uf);
        char cidade[50];
        strcpy(cidade, aux->cidade);
        strcpy(aux->cidade, menor->cidade);
        strcpy(menor->cidade, cidade);
        char categoria[15];
        strcpy(categoria, aux->categoria);
        strcpy(aux->categoria, menor->categoria);
        strcpy(menor->categoria, categoria);
        float medias[5];
        for(int i=0; i<5; i++){
            medias[i] = aux->medias[i];
            aux->medias[i] = menor->medias[i];
            menor->medias[i] = medias[i];
        }
        aux = aux->prox;
    }
    return lista;
}

escola* ordenacaoPorPosicao(escola *lista){
    escola *aux = lista;
    escola *aux2 = lista;
    escola *menor;
    while(aux != NULL){
        menor = aux;
        aux2 = aux->prox;
        while(aux2 != NULL){
            if(aux2->matricula < menor->matricula){
                menor = aux2;
            }
            aux2 = aux2->prox;
        }
        escola *ponteiro = aux->prox;
        aux->prox = menor->prox;
        menor->prox = ponteiro;
        aux = aux->prox;
    }
    return lista;
}

double calculaTempo(clock_t t0, clock_t t1){
    return (((double) (t1 - t0)) / CLOCKS_PER_SEC);
}

int main(void){
    escola *listaEscolas;
    clock_t t0, t1;

    t0 = clock();
    int len = leArquivo(&listaEscolas);
    t1 = clock();
    double tempoLeitura = calculaTempo(t0, t1);
    printf("Total de escolas lidas: %d\n", len);
    printf("Tempo de leitura: %.2f segundos\n", tempoLeitura);

    t0 = clock();
    ordenacaoPorConteudo(listaEscolas);
    t1 = clock();
    double tempoOrdenacaoConteudo = calculaTempo(t0, t1);

    t0 = clock();
    listaEscolas = ordenacaoPorPosicao(listaEscolas);
    t1 = clock();
    double tempoOrdenacaoPosicao = calculaTempo(t0, t1);

    printf("Tempo de ordenação por conteúdo: %.2f segundos\n", tempoOrdenacaoConteudo);
    printf("Tempo de ordenação por posição: %.2f segundos\n", tempoOrdenacaoPosicao);
    printEscolas(listaEscolas);
}