#include <stdio.h>
int main(){
    int numero;
    char titulo[100000];
    scanf("%d %s", &numero, titulo);
    int par = 0;

    for(int i = 0; i < numero; i++){
        for(int j = 0; j < numero; j++){
            if(titulo[i] == titulo[j] && i != j){
                par++;
            }
        }
    }
    par /= 2;

    if(numero % 2 == 0 && par == numero/2 || numero % 2 != 0 && par == (numero - 1)/2){
        printf("Sim\n");
    }else{
        printf("Nao\n");
    }
}

