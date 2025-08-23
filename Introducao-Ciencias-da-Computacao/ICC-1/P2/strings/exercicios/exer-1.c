// Faça um programa que imprima o
// tamanho de uma string fornecida pelo
// usuário. Não use strlen()!

#include <stdio.h>
int main(){
    char string[20];

    printf("Escreva uma string\n");
    scanf("%19[^\n]s", string);

    printf("string: '%s'\n", string);
    
    int contador;

    for(int i = 0; string[i] != '\0'; i++){
        contador = i;

        if(string[i] != '\0'){
            contador++;
        }
    }
    
    printf("tamanho da string: %d\n", contador);

}