#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
    struct No *root;
} vila;

struct Set{
    vila *raiz;
    struct Set *prox;
} *estradas;

// Métodos para tratar estrutura de Set

void add(vila* v){
    int existe = 0;
    struct Set* no = (struct Set*)malloc(sizeof(struct Set));
    no->raiz = v;
    no->prox = NULL;

    if(estradas == NULL){
        estradas = no;
    } else{
        struct Set* aux = estradas;
        while (aux->prox != NULL){
            if(aux->raiz == no->raiz){
                existe = 1;
                break;    
            }
            aux = aux->prox;
        }
        if(aux->raiz == no->raiz){
            existe = 1;
        }
        if (existe == 0){
            aux->prox = no;
        }
    }
}

int sizeEstradas(){
    int count = 0;
    struct Set* aux = estradas;
    if (estradas == NULL) return 0;
    while(aux->prox != NULL){
        aux = aux->prox;
        count++;
    }
    return ++count;
}

vila* getEstrada(int indice){
    struct Set* aux = estradas;
    int i = 0;
    while(aux->prox != NULL && i < indice){
        aux = aux->prox;
        i++;
    }
    return aux->raiz;
}

void setEstrada(int indice, vila* v){
    struct Set* aux = estradas;
    int i = 0;
    while(aux->prox != NULL && i < indice){
        aux = aux->prox;
        i++;
    }
    aux->raiz = v;
}

void sortEstradas(){
    int i=0, j=1;
    vila *aux;

    while(j < sizeEstradas()){
        aux = getEstrada(j);
        i=j-1;
        while((i>=0) && (getRank(getEstrada(i))>getRank(aux))){
            setEstrada(i+1, getEstrada(i));
            i--;
        }
        setEstrada(i+1, aux);
        j++;
    }
}

// Métodos para tratar com a estrutura das vilas

vila* createVila(int valor){
    vila *v = (vila*)malloc(sizeof(vila));
    v->valor=valor;
    v->prox=NULL;
    v->root=v;
    return v;
}

int getRank(vila* v){
    int count = 0;
    while(v->prox != NULL){
        count++;
        v = v->prox;
    }
    return count;
}

int getLast(vila* v){
    vila *aux = v;
    while( aux->prox != NULL){
        aux = aux->prox;
    }
    return aux->valor;
}

vila* myFind(vila* v){
    return v->root;
}

void myUnion(vila* v1, vila* v2){
    vila *parent, *son;
    if (getRank(v1->root) >= getRank(v2->root)){
        parent = v1->root;
        son = v2->root;
    } else{
        parent = v2->root;
        son = v1->root;
    }
    son->root = parent->root;
    while(parent->prox != NULL){
        parent = parent->prox;
    }
    parent->prox = son;
}

int main(void){
    int n, m;

    scanf("%d", &n);
    scanf("%d", &m);

    vila* vilas[n];
    for(int i=0; i<n; i++ ){
        vilas[i] = createVila(i+1);
    }

    for (int i=0; i< m; i++){
        int v1, v2;
        scanf("%d", &v1);
        scanf("%d", &v2);
        myUnion(vilas[v1 - 1], vilas[v2 - 1]);
    }

    for (int i = 0; i<n; i++){
        add(myFind(vilas[i]));
    }
    sortEstradas();

    if(sizeEstradas() == 1){
        printf("Todas as vilas estão conectadas\n");
    }else{
        printf("Não estão todas conectadas. Você precisa de %d estradas adicionais.\n", sizeEstradas() - 1);
        printf("Sugerido: ");
        struct Set* aux = estradas;
        while(aux->prox != NULL){
            printf("Conectar a vila %d com a vila %d; ", aux->raiz->valor, getLast(aux->prox->raiz));
            aux = aux->prox;
        }
        printf("\n");
    }



    return 0;
}