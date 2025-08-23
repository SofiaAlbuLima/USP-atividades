// Faça um programa em C que leia 10 números inteiros e os armazene em um
// vetor. Em seguida, realize a ordenação desses elementos, armazenando eles no
// próprio vetor. Por fim, imprima o resultado.

#include <stdio.h>
int main(){
    int vetor[10];
    for(int i = 0; i < 10; i++){
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < 10; i++){ // 2
        for(int j = 0; j < 10; j++){ //1, 3, 4, 5, 6, 7, 8, 9, 10
            if(i != j && vetor[j] > vetor[j + 1]){

            }
        }
    }
}