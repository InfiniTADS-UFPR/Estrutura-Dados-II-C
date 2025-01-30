#include<stdio.h>

void update(int tree[], size_t arr_lenght, int i, int value){
	while(i < arr_lenght){
		tree[i] += value;
		i += i & -i;
	}
}

int get_sum(int tree[], int i){
	int sum = 0;
	while(i > 0){
		sum += tree[i];
		i -= i & -i;
	}
	return sum;
}

int get_value(int tree[], int i){
	return get_sum(tree, i) - get_sum(tree, i - 1);
}

int main(void){
	int vet[] = {0, 3, 5, 8, 10, 15, 28};
	int vet_size = sizeof(vet) / sizeof(vet[0]);
	int fenwick_tree[] = {0, 0, 0, 0, 0, 0, 0}; 

	for(int i = 1; i < vet_size; i++){
		update(fenwick_tree, vet_size, i, vet[i]);
	}

	printf("%d\n", get_sum(fenwick_tree, 1)); //3
	printf("%d\n", get_sum(fenwick_tree, 2)); //8
	printf("%d\n", get_sum(fenwick_tree, 5)); //41

	printf("%d\n", get_value(fenwick_tree, 1)); //3
	printf("%d\n", get_value(fenwick_tree, 2)); //5
	printf("%d\n", get_value(fenwick_tree, 5)); //15
}
