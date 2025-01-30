#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
} lista;

void add(lista **v, int valor){
    lista *no = (lista*)malloc(sizeof(lista));
    no->valor = valor;
    no->prox = NULL;
    if(*v == NULL){
        *v = no;
    } else{
        lista *aux = *v;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
}

void printLista(lista *v){
    lista *aux = v;
    if(v == NULL){
        printf("[]\n");
        return;
    }
    printf("[");
    while (aux->prox != NULL){
        printf("%d, ", aux->valor);
        aux = aux->prox;
    }
    printf("%d]\n", aux->valor);
}

lista *buscaSimples(int valor, lista *vetor){
    lista *achados = NULL;
    lista *aux = vetor;
    int count = 0;
    while (aux != NULL){
        if(aux->valor == valor){
            add(&achados, count);
        }
        aux = aux->prox;
        count++;
    }
    return achados;
}

lista* buscaBinaria(int valor, int inicio, int fim, lista *vetor) {
    lista *achados = NULL;
    if (inicio >= fim) return achados;

    int aux = (fim - inicio) / 2 + inicio;
    lista *temp = vetor;
    for (int i = 0; i < aux; i++) {
        temp = temp->prox;
    }

    if (temp->valor == valor) {
        add(&achados, aux);
        lista *esquerda = buscaBinaria(valor, inicio, aux, vetor);
        lista *direita = buscaBinaria(valor, aux + 1, fim, vetor);

        if (esquerda != NULL) {
            lista *temp = esquerda;
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = achados;
            achados = esquerda;
        }
        if (direita != NULL) {
            lista *temp = achados;
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = direita;
        }
    } else if (temp->valor > valor) {
        achados = buscaBinaria(valor, inicio, aux, vetor);
    } else {
        achados = buscaBinaria(valor, aux + 1, fim, vetor);
    }
    return achados;
}

void sort(lista **v) {
    if (*v == NULL) return;

    int trocado;
    lista *ptr1;
    lista *lptr = NULL;

    do {
        trocado = 0;
        ptr1 = *v;

        while (ptr1->prox != lptr) {
            if (ptr1->valor > ptr1->prox->valor) {
                int temp = ptr1->valor;
                ptr1->valor = ptr1->prox->valor;
                ptr1->prox->valor = temp;
                trocado = 1;
            }
            ptr1 = ptr1->prox;
        }
        lptr = ptr1;
    } while (trocado);
}

int main(void){
    lista *vetor = NULL;
    add(&vetor, 3);
    add(&vetor, 8);
    add(&vetor, 1);
    add(&vetor, 7);
    add(&vetor, 3);
    add(&vetor, 8);
    add(&vetor, 3);

    printf("Vetor usado para pesquisa: "); printLista(vetor);
    sort(&vetor);
    printf("Vetor ordenado: "); printLista(vetor);


    lista *achados = buscaSimples(3, vetor);
    printf("Elemento 3 encontrado em (busca simples): ");printLista(achados);
    achados = buscaBinaria(3, 0, 7,vetor);
    printf("Elemento 3 encontrado em (busca binaria): ");printLista(achados);
    achados = buscaSimples(16, vetor);
    printf("Elemento 16 encontrado em (busca simples): ");printLista(achados);
    achados = buscaBinaria(16, 0, 7,vetor);
    printf("Elemento 16 encontrado em (busca binaria): ");printLista(achados);
}
