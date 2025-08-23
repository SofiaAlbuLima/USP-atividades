#include <stdio.h>
#include <stdlib.h>

void swap(int **x, int **y){
    int* variavel_temporaria = *x; //armazenando temporariamente o valor de uma das variaveis
        *x = *y; //copiando o valor da segunda para a primeira
        *y = variavel_temporaria; //usando o valor temporario para atualizar a segunda
    
}

int main(){
    int livroA, livroB, livroC, acao;
    scanf("%d %d %d", &livroA, &livroB, &livroC);

    int* cartaoA = &livroA;
    int* cartaoB = &livroB;
    int* cartaoC = &livroC;

    int* array[] = {cartaoA, cartaoB, cartaoC};

    for(int i = 0; i < 3; i++){
        scanf("%d", &acao);
        if(acao == -1){
            array[i] = NULL;
        }else if(acao == 0){
            *(array[i]) = *(array[i]) + 1;
        }else if(acao == 1){
            swap(&array[i], &array[0]);
        }else if(acao == 2){
            swap(&array[i], &array[1]);
        }else if(acao == 3){
            swap(&array[i], &array[2]);
        }else{
            return 0;
        }
    }
    for(int i = 0; i < 3; i++){
        if(array[i] == NULL){
            printf("cartao%d -> Livro fora da estante\n", i+1);
        }else{
            printf("cartao%d -> %d\n", i+1, *(array[i]));
        }
    }
}