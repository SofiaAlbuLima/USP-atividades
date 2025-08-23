#include <stdio.h>
int main(){
    int x;
    scanf("%d", &x);
    double divisao;
    double resultado = x;
    double fatorial = 1;
    double quadrado = 1;
    int sinal = -1;
    for(int i = 3; i <= 43; i += 2){
        printf("i= %d\n", i);
        for(int j = i; j > 0; j--){
            fatorial *= j;
            if(i <= 23){
                printf("j= %d\n", j);
            }
        }
        quadrado *= x*x;
        divisao = quadrado / fatorial;
        if(i <= 23){
            printf("%.15lf = %lf / %lf\n", divisao, quadrado, fatorial);
        }

        resultado += sinal * divisao;
    
        printf("resultado %lf\n", resultado);

        sinal *= -1;
        fatorial = 1;
    }
    printf("%.15lf\n", resultado); 
}