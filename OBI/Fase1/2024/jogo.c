#include <stdio.h>
int main(){
    // matriz NxN
    int N, Q;
    scanf("%d %d", &N, &Q);
    getchar();

    if(N < 1 || N > 50 || Q < 1 || Q > 100){
        return 1;
    }

    int matriz[N][N];
    char linha[N + 1]; //incluir '/0'

    for(int i = 0; i < N; i++){
        fgets(linha, sizeof(linha), stdin);
        getchar();

        for(int j = 0; j < N; j++){
            matriz[i][j] = linha[j] - '0';
        }
    }
    
    // calcular vizinhas
    int vizinhos[N][N];
    if(N == 1){
        printf("sem vizinhos");
    }else{ //N = 3 ou maior
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if((i == 0 || i == N-1) && (j == 0 || j == N-1)){
                    vizinhos[i][j] = 3;
                }else if(((i == 0 || i == N-1) || (j == 0 || j == N-1)) && ((i != 0 || i != N-1) || (j != 0 || j != N-1))){
                    vizinhos[i][j] = 5;
                }else{
                    vizinhos[i][j] = 8;
                }
            }
        }
    }

    // regras

    return 0;
}