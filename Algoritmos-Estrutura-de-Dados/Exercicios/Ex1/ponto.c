#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h"

typedef struct ponto_{
    float x;
    float y;
} PONTO;

PONTO* ponto_criar(float x, float y){ //a função retorna um ponteiro para um ponto
    PONTO* ponto = (PONTO*) malloc(sizeof(PONTO));
    ponto->x = x;
    ponto->y = y;

    return ponto;
}

void ponto_apagar(PONTO* p){
    free(p);
    return;
}

bool ponto_set(PONTO *p, float x, float y){
    if(p && x && y){
        p->x = x;
        p->y = y;
        return true;
    }else{
        return false;
    }
}

void imprimir_ponto(PONTO *p){
    printf("%f %f\n", p->x, p->y);
    return;
}

// no ponto.c conseguimos acessar os elementos de PONTO, então precisa dessa função aqui :)
float distancia_ponto_ponto(PONTO *A, PONTO *B){
    float elemA = pow(A->x - B->x, 2);
    float elemB = pow(A->y - B->y, 2);
    return sqrt(elemA + elemB);
}