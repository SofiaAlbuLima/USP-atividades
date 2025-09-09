#ifndef BUNDINHA
    #define BUNDINHA
    #include <stdio.h>
    #define PI 3.14159625

    typedef struct _ponto{ //struct e variáveis constantes são sempre no .h
        float x;
        float y;
    } PONTO;

    PONTO* criar_ponto(float x, float y);

    float distancia(PONTO* A, PONTO* B);

    void rotar_ponto(PONTO* A, float teta);

    void imprimir_ponto(PONTO* A);

    void derreter_ponto(PONTO* A);
#endif