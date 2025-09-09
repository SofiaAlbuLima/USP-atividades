#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"

CIRCLU* criar_circulo(PONTO* A, float raio){
    CIRCLU* C = (CIRCLU*) malloc(sizeof(CIRCLU));
    C->centro = A; //os tres sao ponteiros
    C->raio = raio;

    return C;
}

float distancia_ponto_centro(PONTO* A, CIRCLU* C){
    return distancia(A, C->centro);
}

float raio_do_circulo(CIRCLU* C){
    return C->raio;
}

void obliterar_circulo(CIRCLU* C){
    free(C->centro);
    free(C);
    return;
}