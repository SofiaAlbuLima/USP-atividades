#include <stdio.h>

void swap(int *controleA, int *controleB){
     long variavel_temporaria = *controleA; //armazenando temporariamente o valor de uma das variaveis
     *controleA = *controleB; //copiando o valor da segunda para a primeira
     *controleB = variavel_temporaria; //usando o valor temporario para atualizar a segunda
}

int main(){
    int canalA, canalB;
    scanf("%d %d", &canalA, &canalB);

    int* controleA = &canalA;
    int* controleB = &canalB;

    swap(controleA, controleB);

    printf("%d %d\n", *controleA, *controleB);
}