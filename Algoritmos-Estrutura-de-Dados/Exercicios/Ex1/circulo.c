#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h"
#include "circulo.h"
#define PI 3.14159625

typedef struct circulo_{
    PONTO* centro;
    float raio;
} CIRCULO;

CIRCULO* circulo_criar(PONTO *p, float raio){
    CIRCULO* circulo = (CIRCULO*) malloc(sizeof(CIRCULO));
    circulo->centro = p;
    circulo->raio = raio;

    return circulo;
}

void circulo_apagar(CIRCULO* circ){
    free(circ);
}

float circulo_area (CIRCULO* circ){
    float area = PI*(pow(circ->raio, 2));
    return area;
}

void imprimir_circulo(CIRCULO* circ){
    imprimir_ponto(circ->centro);
    printf("%f\n", circ->raio);
}

//chamei essa função aqui pois só aqui posso acessar o elemento circulo, diferentemente do ponto.c
float distancia_ponto_centro(PONTO* p, CIRCULO* r){
    return distancia_ponto_ponto(p, r->centro);
}