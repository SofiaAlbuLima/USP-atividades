#include <stdio.h>
#include "circulo.h"
#include "ponto.h"

int main(){
    float px, py, cx, cy, raio;
    scanf("%f %f %f %f %f", &px, &py, &cx, &cy, &raio);

    PONTO* ponto = ponto_criar(px, py);
    PONTO* centro = ponto_criar(cx, cy);
    CIRCULO* circulo = circulo_criar(centro, raio);

    /*
    printf("Ponto: ");
        imprimir_ponto(ponto);
    printf("Circulo: ");
        imprimir_circulo(circulo);
    */

    float distancia = distancia_ponto_centro(ponto, circulo);

    if(distancia > raio){
        printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", distancia); 
    }else if(distancia < raio){
        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", distancia); 
    }else{
        printf("O ponto pertence à circunferência.\nDistância: %.2f\n", distancia); 
    }

    /* MUDAR A COORDENADA DO PONTO E ÁREA DO CIRCULO
    float area_circulo = circulo_area(circulo);
    printf("Area do circulo: %f\n", area_circulo);

    printf("mude a coordenada do ponto: \n");
    scanf("%f %f", &px, &py);
    if(ponto_set(ponto, px, py) == true){
        printf("ponto alterado para: ");
            imprimir_ponto(ponto);
    }else{
        printf("ponto não alterado!\n");
    }
    */
    circulo_apagar(circulo);
    ponto_apagar(ponto);
}