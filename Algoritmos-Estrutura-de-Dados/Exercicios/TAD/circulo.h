#include <stdio.h>
#include "ponto.h"

typedef struct _circle{
    PONTO* centro;
    float raio;
} CIRCLU;

CIRCLU* criar_circulo(PONTO* A, float raio);
float distancia_ponto_centro(PONTO* A, CIRCLU* C);
float raio_do_circulo(CIRCLU* C);
void obliterar_circulo(CIRCLU* C);