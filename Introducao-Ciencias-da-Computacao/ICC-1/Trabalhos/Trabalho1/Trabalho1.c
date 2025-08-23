#include <stdio.h>
#include <math.h>
#define PI 3.141592
int main(){
    int ordem_da_matriz; 
    scanf("%d", &ordem_da_matriz);

    if(ordem_da_matriz <= 0){
        return 1; //caso o usuário tente dar entrada à uma matriz com ordem 0 ou menor (o que não faz sentido!)
    }

    double matriz_inicial[ordem_da_matriz][ordem_da_matriz]; //Matriz criada de acordo com sua ordem
    double matriz_final[ordem_da_matriz][ordem_da_matriz];

    for(int i = 0; i < ordem_da_matriz; i++){ //inicializando os elementos da matriz inicial
        for(int j = 0; j < ordem_da_matriz; j++){ 
            scanf("%lf", &matriz_inicial[i][j]); 
        }
    }

    for (int i = 0; i < ordem_da_matriz; i++) { //Cálculo do DCT bidimensional
        for (int j = 0; j < ordem_da_matriz; j++) {
            double normal_i; //fator de normalização da linha
            double normal_j; //fator de normalização da coluna
            double soma = 0;

            normal_i = (i == 0) ? 1/sqrt(ordem_da_matriz) : sqrt(2)/sqrt(ordem_da_matriz);
            normal_j = (j == 0) ? 1/sqrt(ordem_da_matriz) : sqrt(2) / sqrt(ordem_da_matriz);

            for(int x = 0; x < ordem_da_matriz; x++){
                for(int y = 0; y < ordem_da_matriz; y++){
                    double cos_x = cos((2 * x + 1)* i * PI / (2 * ordem_da_matriz));
                    double cos_y = cos((2 * y + 1)* j * PI / (2 * ordem_da_matriz));
                    soma += matriz_inicial[x][y] * cos_x * cos_y; //adicionando à soma a multiplicação entre cosx, cosy para cada linha/coluna da matriz inicial
                }
            }
            matriz_final[i][j] = normal_i * normal_j * soma;
            printf("%9.3lf ", matriz_final[i][j]);
        }
        printf("\n"); // Nova linha para cada linha da matriz (apenas formatação)
    }
}