// Desenvolva um programa que encontre o maior elemento em um vetor de
// números reais, positivos, de tamanho n. 
// n e os elementos devem ser fornecidos pelo usuário em uma etapa anterior 
// à procura pelo maior elemento. Imprima o maior elemento.

#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    float vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%f", &vetor[i]);
        if(vetor[i] < 0){
            return 1;
        }
    }
    float maior_numero = vetor[0];
    for(int i = 1; i < n; i++){
        if(vetor[i] > maior_numero){
            maior_numero = vetor[i];
        }
    }
    printf("O maior elemento é o: %f\n", maior_numero);

    printf("vetor: ");
    for(int i = 0; i < n; i++){
        printf("%f ", vetor[i]);
    }
}