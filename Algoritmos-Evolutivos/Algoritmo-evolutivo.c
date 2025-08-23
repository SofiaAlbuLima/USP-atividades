#include <stdio.h>
#include <stdlib.h>

#define quantidade_solucoes 10
#define grupo 6
#define max_geracoes 5
#define taxa_mutacao 20

    int funcao(int x){
        return x * 3 + 5;
    }

    int fitness(int x){
        int resultado_fitness = abs(funcao(x) - 20);
        printf("fitness de %d: %d\n", x, resultado_fitness);
        return resultado_fitness;
    }

    int crossover(int pai1, int pai2) {
        return (pai1 + pai2) / 2;
    }

    int mutacao(int x) {
        if (rand() % 100 < taxa_mutacao) {
            int delta = (rand() % 3) - 1;
            x = x + delta;
            if (x < 0) x = 0;
            if (x > 9) x = 9;
        }
        return x;
    }

int main(){
    printf("Vamos encontrar um valor de x entre 0 e 9 tal que f(x) = y seja 20!\n");

    int solucoes[quantidade_solucoes]; //população inicial

    for(int i = 0; i < grupo; i++){
        solucoes[i] = rand() % 10; //numeros entre 0 e 9
        printf("solucao: %d\n", solucoes[i]);
    }
    

    for(int geracao = 0; geracao < max_geracoes; geracao++){
        int melhor = solucoes[0];
        int melhorFitness = fitness(melhor);

        for(int i = 0; i < grupo; i++){ //selecionando os melhores fitness
            int fit = fitness(solucoes[i]);
            if(fit < melhorFitness){
                melhor = solucoes[i];
                melhorFitness = fit;
            }
        }
        printf("Geracao %d: Melhor x = %d, f(x) = %d, fitness = %d\n", geracao, melhor, funcao(melhor), melhorFitness);
        if (melhorFitness == 0) break;

        for (int i = 0; i < grupo; i++) {
            int pai1 = solucoes[rand() % quantidade_solucoes];
            int pai2 = solucoes[rand() % quantidade_solucoes];
            int filho = crossover(pai1, pai2);
            filho = mutacao(filho);
            solucoes[i] = filho;
        }
    }
    
}