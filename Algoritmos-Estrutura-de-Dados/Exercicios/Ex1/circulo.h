#ifndef CIRCULO_H
    #define CIRCULO_H
    #include "ponto.h"

    typedef struct circulo_ CIRCULO;
    CIRCULO *circulo_criar(PONTO *p, float raio);
    void circulo_apagar (CIRCULO* circ);
    float circulo_area (CIRCULO* circ); 
    void imprimir_circulo (CIRCULO* circ); //função criada aqui para fazer testes
    float distancia_ponto_centro(PONTO* p, CIRCULO* r);

#endif