#include <stdio.h>

int main(void){
    int a, b, c;

    printf("a: %d, b; %d, c:%d\n", a, b, c);
    printf("Insira um novo valor para a: ");
    scanf("%d", &a);
    printf("Insira um novo valor para b: ");
    scanf("%d", &b);
    printf("a: %d, b; %d, c:%d\n", a, b, c);
    
    return 0;
}