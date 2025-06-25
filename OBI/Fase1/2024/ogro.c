#include <stdio.h>
int main(){
    int E, D, resultado = 0;

    scanf("%d", &E);
    scanf("%d", &D);
    
    if(E < 0 || E > 5 || D < 0 || D > 5 || E == D){
        printf("erro\n");
        return 1;
    }

    if(E > D){
        resultado = E + D;
    }else{
        resultado = 2*(D - E);
    }
    printf("resultado: %d\n", resultado);
    return 0;
}