#include <stdio.h>
int main(){
    int c[10], i;
    for (i = 0; i < 100; i++)
    c[i] = i;
}

// Erro buffer overflow : Acesso/escrita além dos limites de um array ou região de memória alocada.