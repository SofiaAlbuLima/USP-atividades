#ifndef PONTO_H
    #define PONTO_H
	#include <stdbool.h>
	
    typedef struct ponto_ PONTO;
    PONTO *ponto_criar(float x, float y);
    void ponto_apagar(PONTO *p);
    bool ponto_set(PONTO *p, float x, float y);
    void imprimir_ponto(PONTO *p); //função criada aqui para fazer testes
    float distancia_ponto_ponto(PONTO *A, PONTO *B);

#endif