#include <stdio.h>
#include "circulo.h"
#include "ponto.h"

int main(){
    printf("Escreva as coordenadas do seu ponto: \n");
    float xa, ya;
    scanf("%f %f", &xa, &ya);

    PONTO* ponto_A = criar_ponto(xa, ya);

/*
    printf("Escreva as coordenadas do seu outro ponto: \n");
    float xb, yb;
    scanf("%f %f", &xb, &yb);

    PONTO* ponto_B = criar_ponto(xb, yb);

    float resultado = distancia(ponto_A, ponto_B);

    printf("Resultado: %f\n", resultado);

    printf("Vamos rotar seu ponto, qual teta (grau) você quer?\n");
    float teta;
    scanf("%f", &teta);

    rotar_ponto(ponto_A, teta);
    printf("Rotando ponto A rotado a %f graizis: \n", teta);
    imprimir_ponto(ponto_A);
*/

    printf("Escreva as coordenadas do centro do seu circulo: \n");
    float cx, cy;
    scanf("%f %f", &cx, &cy);
    PONTO* ponto_C = criar_ponto(cx, cy);

    printf("Escreva o raio do seu circulo: \n");
    float raio;
    scanf("%f", &raio);
    CIRCLU* circulo = criar_circulo(ponto_C, raio);

    float dpc = distancia_ponto_centro(ponto_A, circulo);
    if(dpc > raio){
        printf("Seu ponto está fora da casinha!\n");
    }else if(dpc == raio){
        printf("Seu ponto ta no telhado da casinha!\n");
    }else{
        printf("O ponto invadiu sua casa!\n");
    }

    derreter_ponto(ponto_A);
    obliterar_circulo(circulo);
    // derreter_ponto(ponto_B);
    printf("Seus pontos foram derretidos...\n");
}