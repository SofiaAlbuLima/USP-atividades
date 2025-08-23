// Suponha que o vetor A contenha
// valores inteiros em todas as suas 1000
// posições. Faça um laço, em C, para
// somar todos os seus elementos.

#include <stdio.h>
int main(){
    int A[1000];
    int soma = 0;
    for(int i = 0; i<1000; i++){
        A[i] = i + 1;
    }

    for(int i=0; i<1000; i++){
        soma += A[i];
    }
    printf("soma = %d\n", soma);
}