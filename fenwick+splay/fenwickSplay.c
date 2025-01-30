#include <stdlib.h>
#include <stdio.h>

typedef struct fenwick{
    int *vet;
    int *ft;
    int size;
} Fenwick;

typedef struct node{
    Fenwick block;
    struct node *left, *right;
} Splay;

// Lógica Fenwick
Fenwick init_fenwick(){
    Fenwick ft;
    ft.vet = (int *)calloc(10, sizeof(int));
    ft.ft = (int *)calloc(11, sizeof(int));
    ft.size = 10;
    return ft;
}

void print_ft(Fenwick ft){
    int i;
    printf("[");
    for (i = 0; i < ft.size-1; i++){
        printf(" %d,", ft.vet[i]);
    }
    printf(" %d ]\n", ft.vet[i]);
}

void update(Fenwick tree, int i, int value){
    int delta = value - tree.vet[i-1];
    tree.vet[i-1] = value;
	while(i < 11){
		tree.ft[i] += value;
		i += i & -i;
	}
}

int sum(Fenwick tree, int i){
	int sum = 0;
	while(i > 0){
		sum += tree.ft[i];
		i -= i & -i;
	}
	return sum;
}

// Lógica Splay
Splay* new_node(){
    Splay* new = (Splay*)malloc(sizeof(Splay));
    new->block = init_fenwick();
    new->left = new->right = NULL;
    return new;
}

Splay* right_rotate(Splay* x){
    Splay* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Splay* left_rotate(Splay* x){
    Splay* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Splay* splay(Splay* root, int value){
    if(root == NULL || (10-sum(root->block, 10)) == value) return root;
    if((10-sum(root->block,10)) > value){
        if(root->left == NULL) return root;
        if((10-sum(root->left->block,10)) > value){
            root->left->left = splay(root->left->left, value);
            root = right_rotate(root);
        }else if((10-sum(root->left->block,10)) < value){
            root->left->right = splay(root->left->right, value);
            if(root->left->right != NULL) root->left = left_rotate(root->left);
        }
        return (root->left == NULL) ? root : right_rotate(root);
    }else{
        if(root->right == NULL) return root;
        if((10-sum(root->right->block,10)) > value){
            root->right->left = splay(root->right->left, value);
            if(root->right->left != NULL) root->right = right_rotate(root->right);
        }else if((10-sum(root->right->block,10)) < value){
            root->right->right = splay(root->right->right, value);
            root = left_rotate(root);
        }
        return (root->right == NULL) ? root : left_rotate(root);
    }
}

Splay* insert(Splay* root, int turn){
    if(root == NULL) return new_node();
    root = splay(root, sum(root->block, 10));
    Splay* new = new_node();
    if(turn % 2 == 0){
        new->right = root;
        new->left = root->left;
        root->left = NULL;
    }else{
        new->left = root;
        new->right = root->right;
        root->right = NULL;
    }
    return new;
}

Splay* init_splay(){
    Splay *memoria = NULL;
    for (int i = 0; i < 10; i++){
        memoria = insert(memoria, i);
    }
}

void print_pre_order(Splay* root) {
    if (root == NULL) return;
    printf("#%x ", &root->block);
    print_ft(root->block);
    print_pre_order(root->left);
    print_pre_order(root->right);
}

Splay* insert_in_memory(Splay* memoria, int lenght){
    memoria = splay(memoria, lenght);
    for (int i = 0; i < lenght; i++){
        update(memoria->block, sum(memoria->block,10)+1, 1);
    }
    return memoria;
}

int main(void){
    int i = 1;
    Splay *memoria = init_splay();
    printf("Memoria inicial:\n");
    print_pre_order(memoria);
    printf("\n");
    while (i >= 1){
        printf("--//--//--//--//--//--//--//--//--//--//--//--//--//--//\n");
        printf("O que você deseja fazer?\n");
        printf("1 - Inserir dados na memoria?\n");
        printf("2 - Imprimir memoria?\n");
        printf("0 - Sair\n");
        scanf("%d", &i);
        if (i == 1){
            int lenght;
            printf("Quantos dados deseja inserir?\n");
            scanf("%d", &lenght);
            memoria = insert_in_memory(memoria, lenght);
        }else if (i == 2){
            printf("\nEstado da memoria:\n");
            print_pre_order(memoria);
        }
    }
    
}
