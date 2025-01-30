#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int value;
    struct node *left, *right;
}node;

node* new_node(int value){
    node* new = (node*)malloc(sizeof(node));
    new->value = value;
    new->left = new->right = NULL;
    return new;
}

node* right_rotate(node* x){
    node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

node* left_rotate(node* x){
    node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

node* splay(node* root, int value){
    if(root == NULL || root->value == value) return root;
    if(root->value > value){
        if(root->left == NULL) return root;
        if(root->left->value > value){
            root->left->left = splay(root->left->left, value);
            root = right_rotate(root);
        }else if(root->left->value < value){
            root->left->right = splay(root->left->right, value);
            if(root->left->right != NULL) root->left = left_rotate(root->left);
        }
        // zig case
        return (root->left == NULL) ? root : right_rotate(root);
    }else{
        if(root->right == NULL) return root;
        if(root->right->value > value){
            root->right->left = splay(root->right->left, value);
            if(root->right->left != NULL) root->right = right_rotate(root->right);
        }else if(root->right->value < value){
            root->right->right = splay(root->right->right, value);
            root = left_rotate(root);
        }
        // zag case
        return (root->right == NULL) ? root : left_rotate(root);
    }
}

node* insert(node* root, int value){
    if(root == NULL) return new_node(value);
    root = splay(root, value);
    if(root->value == value) return root;
    node* new = new_node(value);
    if(root->value > value){
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

node* search(node* root, int value){
    return splay(root, value);
}

node* delete(node* root, int value){
    if(root == NULL) return NULL;
    root = splay(root, value);
    if(root->value != value) return root;
    node* new_root = NULL;
    if(root->left == NULL) new_root = root->right;
    else{
        new_root = splay(root->left, value);
        new_root->right = root->right;
    }
    free(root);
    return new_root;
}

void free_tree(node* root){
    if(root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void){
    node* root = NULL;
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 28);
}