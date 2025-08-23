#include <stdio.h> 
#include <stdlib.h>
int main(){
    int valor1, valor2; scanf("%d %d", &valor1, &valor2);
    int *ponteiro1 = &valor1;
    int *ponteiro2 = &valor2;

    printf("%d %d\n", *ponteiro1, *ponteiro2);

    int *memoria_alocada = malloc(sizeof(int));
    *memoria_alocada = *ponteiro1;
    *ponteiro1 = *ponteiro2;
    *ponteiro2 = *memoria_alocada;

    printf("%d %d\n", *ponteiro1, *ponteiro2);

    free(memoria_alocada);
}