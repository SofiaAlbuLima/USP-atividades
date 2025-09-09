#ifndef CIRCULO_H
    #define CIRCULO_H
    #include "ponto.h"

    typedef struct circulo_ CIRCULO;
    CIRCULO *circulo_criar(PONTO *p, float raio);
    void circulo_apagar (CIRCULO* circ);
    float circulo_area (CIRCULO* circ); //endereço que aponta para um CIRCULO na memória

#endif


