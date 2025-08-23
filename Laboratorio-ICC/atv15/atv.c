#include <stdio.h>
int main(){
    int numero; scanf("%d", &numero);
    if(numero <= 0){
        return 1;
    }
    double soma;
    double fatorial = 1;
    double divisao;
    int negativo = 1;

    for(int i = 1; i <= numero; i++){ //1, 2, 3
        for(int j = i; j > 0; j--){ //1, 2, 3
            fatorial *= j; //1, 2, 6
        }
        divisao = 1 / fatorial; //1, 1/2, 1/6

        if(i > 2){
            negativo *= -1;
        }

        soma += negativo*divisao;
        fatorial = 1;
    }
    printf("%.6lf\n", soma);
}