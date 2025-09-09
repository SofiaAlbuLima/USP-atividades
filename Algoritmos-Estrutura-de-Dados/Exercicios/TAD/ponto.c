#include <stdio.h>
#include "ponto.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


PONTO* criar_ponto(float x, float y){
    PONTO* A = (PONTO*) malloc(sizeof(PONTO));
    A->x = x;
    A->y = y;  

    return A;
}

float distancia(PONTO* A, PONTO* B){
    float dx = pow((A->x - B->x), 2);
    float dy = pow((A->y - B->y), 2);

    return sqrt(dx + dy);
};

void rotar_ponto(PONTO* A, float teta){
    float rad = (teta*PI)/180;
    float consono = cos(rad);
    float sensono = sin(rad);

    float tempx = A->x;
    float tempy = A->y;

    A->x = consono*tempx + sensono*tempy;
    A->y = -(sensono*tempx) + consono*tempy;



    return;
}

void imprimir_ponto(PONTO* A){
    printf("Seu ponto: %f %f\n", A->x, A->y);
    return;
}

void derreter_ponto(PONTO* A){
    free(A);
    return;
}