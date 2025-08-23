#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int pos = a;         // posição atual do Cap
    int distancia_total = 0;
    int step = 1;        // distância que será andada
    int direcao = 1;     // 1 para direita, -1 para esquerda

    while (1) {
        int destino = a + direcao * step;

        // Verifica se o Alanzoka está entre a posição atual e a próxima
        if ((b >= pos && b <= destino) || (b <= pos && b >= destino)) {
            distancia_total += abs(pos - b);
            break;
        } else {
            distancia_total += abs(pos - destino);
            pos = destino;
            step *= 2;
            direcao *= -1;
        }
    }

    printf("%d\n", distancia_total);
    return 0;
}