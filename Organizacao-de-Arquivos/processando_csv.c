#include <stdio.h>
#include <string.h>

struct colunas{ //Criando uma struct para armazenar os dados, sem se preocupar com padding, já que todos são strings
    char Nome[50];
    char Idade[4];
    char Cidade[50];
};

int main(void){
    /* Processando um arquivo CSV em C:
        | Para processar um CSV em C, combinamos o fgets (para ler cada linha) com o strtok (para separar as colunas)
        -> Um arquivo CSV é apenas um texto, onde cada linha representa um registro e as colunas são separadas por um caractere
        -> O strtok tem uma limitação séria com CSVs: ele pula campos vazios
    */

    FILE *fp = fopen("entradas/dados.csv", "r");
    char linha[1024];

    struct colunas lista_pessoas[100]; //Array de structs, suporta guardar até 100 pessoas
    int i = 0;

    if(fp == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Pulando cabeçalho
    fgets(linha, sizeof(linha), fp);

    // Lendo linha por linha
    while(fgets(linha, sizeof(linha), fp) && i < 100){

        // Removendo \n de cada linha; strcspn devolve o índice do primeiro caractere que corresponde ao "\n"
        linha[strcspn(linha, "\n")] = 0; // Subtituição por 0 (que é equivalente ao terminador nulo '\0')

        // 1. Pega o nome
        char *token = strtok(linha, ",");
        if(token) strcpy(lista_pessoas[i].Nome, token);

        // 2. Pega a Idade
        token = strtok(NULL, ",");
        if(token) strcpy(lista_pessoas[i].Idade, token);

        // 3. Pega a Cidade
        token = strtok(NULL, ",");
        if(token) strcpy(lista_pessoas[i].Cidade, token);

        i++;
    }
    fclose(fp);

    // Imprimindo os registros de Pessoas...
    printf("\nImprimindo dados carregados...\n");
    for(int j = 0; j < i; j++){
        printf("Pessoa %d: %s, %s anos, mora em %s\n", j+1, lista_pessoas[j].Nome, lista_pessoas[j].Idade, lista_pessoas[j].Cidade);
    }
    printf("\n");

    // --- INÍCIO DA GRAVAÇÃO BINÁRIA ---

    FILE *bin_fp = fopen("dados.bin", "wb");
    if (bin_fp == NULL) {
        printf("Erro ao criar arquivo binário!\n");
        return 1;
    }

    /* Usando fwrite:
        -> Sintaxe:
            fwrite(&variavel, tamanho_da_struct, quantidade, ponteiro_do_arquivo);
    */

    // Grava o array 'lista_pessoas' inteiro de uma só vez
    // 'i' é o contador de quantas pessoas foram lidas do CSV
    size_t gravados = fwrite(lista_pessoas, sizeof(struct colunas), i, bin_fp);

    if (gravados == i) {
        printf("Sucesso! %d registros salvos em 'dados.bin'.\n\n", i);
    }

    fclose(bin_fp);
    
    return 0;
}