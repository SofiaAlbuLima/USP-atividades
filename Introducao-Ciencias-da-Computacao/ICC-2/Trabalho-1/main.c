#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
        int peso;
        int valor;
    } ITEM;

int melhor_valor = 0;
int *melhor_comb;

void Forca_Bruta(ITEM itens[], int n_itens, int capacidade_mochila, int escolhido, int peso_atual, int valor_atual, int combinacao[]){
    // Caso base: já consideramos todos os itens
    if(escolhido == n_itens){
        if(peso_atual <= capacidade_mochila && valor_atual > melhor_valor){
            melhor_valor = valor_atual;
            for(int j = 0; j < n_itens; j++){
                melhor_comb[j] = combinacao[j];
            }
        }

        return;
    }

    //Caso 1: não escolher um item para incluir
    combinacao[escolhido] = 0;
    Forca_Bruta(itens, n_itens, capacidade_mochila, escolhido + 1, peso_atual, valor_atual, combinacao);

    //Caso 2: escolher um item para incluir (se couber)
    if(peso_atual + itens[escolhido].peso <= capacidade_mochila){
        combinacao[escolhido] = 1;
        Forca_Bruta(itens, n_itens, capacidade_mochila, escolhido + 1,
                    peso_atual + itens[escolhido].peso,
                    valor_atual + itens[escolhido].valor,
                    combinacao);
    }
};

void Algoritmo_Guloso(ITEM itens[], int n_itens, int capacidade_mochila){
    //struct auxiliar para a razão valor/peso
    typedef struct{
        int id;
        double razao;
    } INFO;
    
    INFO info[n_itens];

    //Calculo da razao valor/peso para cada item
    for(int i = 0; i < n_itens; i++){
        info[i].id = i;
        info[i].razao = ((double) itens[i].valor/itens[i].peso);
    }

    //Odernando os itens pela razão (ordem decrescente) - Por Selection Sort
    for(int i = 0; i < n_itens-1; i++){
        for(int j = i; j < n_itens; j++){
            if(info[j].razao > info[i].razao){
                INFO temp = info[i];
                info[i] = info[j];
                info[j] = temp;
            }
        }
    }

    int peso_total = 0;
    int valor_total = 0;
    int *itens_escolhidos = calloc(n_itens, sizeof(int));

    // Seleciona itens enquanto couberem
    for (int i = 0; i < n_itens; i++) {
        int sel = info[i].id;
        if (peso_total + itens[sel].peso <= capacidade_mochila) {
            peso_total += itens[sel].peso;
            valor_total += itens[sel].valor;
            itens_escolhidos[sel] = 1;
        }
    }

    // Mostra o resultado
    printf("\nCom Algoritmo Guloso:\n");
    printf("Valor total aproximado: %d\n", valor_total);
    printf("Itens escolhidos:\n");
    for (int i = 0; i < n_itens; i++) {
        if (itens_escolhidos[i])
            printf("    Item %d (peso = %d, valor = %d)\n", i + 1, itens[i].peso, itens[i].valor);
    }

    free(itens_escolhidos);
};

void Programacao_Dinamica(ITEM itens[], int n_itens, int capacidade_mochila){
    int i; //número de itens considerados
    int w; //peso total possível

    // Cria matriz dinam_prog: n_itens+1 x capacidade_mochila+1
    int **dinam_prog = (int **) malloc((n_itens + 1) * sizeof(int *));
    for (i = 0; i <= n_itens; i++)
        dinam_prog[i] = (int *) malloc((capacidade_mochila + 1) * sizeof(int));

    // Inicializa a tabela
    for (i = 0; i <= n_itens; i++) {
        for (w = 0; w <= capacidade_mochila; w++) {
            if (i == 0 || w == 0)
                dinam_prog[i][w] = 0;
            else if (itens[i-1].peso <= w)
                dinam_prog[i][w] = (itens[i-1].valor + dinam_prog[i-1][w - itens[i-1].peso] > dinam_prog[i-1][w]) ?
                            itens[i-1].valor + dinam_prog[i-1][w - itens[i-1].peso] :
                            dinam_prog[i-1][w];
            else
                dinam_prog[i][w] = dinam_prog[i-1][w];
        }
    }

    int melhor_valor_pd = dinam_prog[n_itens][capacidade_mochila];

    // Descobre quais itens foram escolhidos
    int *itens_escolhidos = calloc(n_itens, sizeof(int));
    w = capacidade_mochila;
    for (i = n_itens; i > 0 && melhor_valor_pd > 0; i--) {
        if (melhor_valor_pd != dinam_prog[i-1][w]) {
            itens_escolhidos[i-1] = 1;
            melhor_valor_pd -= itens[i-1].valor;
            w -= itens[i-1].peso;
        }
    }

    // Exibe resultados
    printf("\nCom Programacao Dinamica:\n");
    printf("Melhor valor possivel: %d\n", dinam_prog[n_itens][capacidade_mochila]);
    printf("Itens escolhidos:\n");
    for (i = 0; i < n_itens; i++) {
        if (itens_escolhidos[i])
            printf("    Item %d (peso = %d, valor = %d)\n", i + 1, itens[i].peso, itens[i].valor);
    }

    // Libera memória
    for (i = 0; i <= n_itens; i++)
        free(dinam_prog[i]);
    free(dinam_prog);
    free(itens_escolhidos);
};

int main(){
    //variáveis para medir o tempo de execução
    clock_t inicio, fim;
    double tempo_execucao;

    int capacidade_mochila, n_itens; 

    printf("\nDetermine a capacidade (peso) total da mochila: ");
    scanf("%d", &capacidade_mochila);
    
    printf("\nDetermine a quantidade de itens que você pode colocar: ");
    scanf("%d", &n_itens);
    printf("\n");    

    ITEM itens[n_itens];
    int combinacao[n_itens];
    melhor_comb = malloc(n_itens * sizeof(int));

    for(int i = 0; i<n_itens; i++){
        printf("%d) Peso do item: ", i+1);
            scanf("%d", &itens[i].peso);
        printf("%d) Valor do item: ", i+1);
            scanf("%d", &itens[i].valor);
        printf("\n");    
        combinacao[i] = 0;
        melhor_comb[i] = 0;
    }

    // Força Bruta
    inicio = clock();
    Forca_Bruta(itens, n_itens, capacidade_mochila, 0, 0, 0, combinacao);
    printf("\nCom Forca Bruta:\n");
        printf("Melhor valor possivel: %d", melhor_valor);

        printf("\nItens escolhidos:\n");
        for(int i = 0; i< n_itens; i++){
            if (melhor_comb[i])
                printf("    Item %d (peso = %d, valor = %d)\n", i + 1, itens[i].peso, itens[i].valor);
        }
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao (Forca Bruta): %.6f segundos\n", tempo_execucao);

    
    // Algoritmo Guloso
    inicio = clock();
    Algoritmo_Guloso(itens, n_itens, capacidade_mochila);
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao (Algoritmo Guloso): %.6f segundos\n", tempo_execucao);


    // Programacao Dinamica
    inicio = clock();
    Programacao_Dinamica(itens, n_itens, capacidade_mochila);
    fim = clock();
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao (Prog. Dinamica): %.6f segundos\n", tempo_execucao);
    

    printf("\n");
    free(melhor_comb);
    return 0;

}