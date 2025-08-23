// Faça um programa que preencha um vetor com 10 números inteiros,
// positivos, fornecidos pelo usuário. Após esse passo, o programa deve percorrer
// o vetor para contar a quantidade de números pares maiores que 10
// presentes no vetor. Imprima a quantidade.

#include <stdio.h>
int main(){
    int vetor[10];
    int pares = 0;

    for(int i = 0; i < 10; i++){
        scanf("%d", &vetor[i]);
        if(vetor[i] > 0){
            if(vetor[i] % 2 == 0 && vetor[i] > 10){
                pares += 1;
            }
        }else{
            return 1;
        }
    }
    printf("temos %d numeros pares maior que 10 no vetor!\n", pares);
    printf("vetor: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }
}