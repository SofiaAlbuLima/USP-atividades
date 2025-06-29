#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define ARQUIVO "registros.json"

void insercao_de_dados(int id, const char *login, char *password, ){

}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Objetivo: inserção, busca e remoção de dados

    // Dados de inserção:
    int id;    char login[100];    char password[100];    char gender[100];    double salary;
    int operacao, registros_feitos, registros_totais[1000];
    char linha[100];

    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%d %d \"%[^\"]\" \"%[^\"]\" \"%[^\"]\" %lf", &operacao, &id, login, password, gender, &salary);

    // Casos de erro nos tipos de dados e tamanhos:
    if(id > 1000 || id < 0){
        printf("erro no id\n");
        return 1;
    }
    if(strlen(login) > 14 || strlen(password) > 29 || strlen(gender) > 1){
        printf("erro nas strings\n");
        return 1;
    }
    // contato com o banco:
    FILE *banco;
    
    if(operacao == 1){
        printf("operacao: inserção\n");

    }else if(operacao == 2){
        printf("operacao: alteração\n");
    }else if(operacao == 3){
        printf("operacao: busca\n");
    }else{
        printf("erro de operação\n");
        return 1;
    }

    printf("%d %d %s %s %s %lf\n", operacao, id, login, password, gender, salary);

    // if(registros_totais == 1000){
    //     printf("Sem espaço para inserção.");
    // }

    // printf("%d registro(s) lido(s).\n", registros_feitos);
    return 0;
}

// 1 33 "login_xyz" "pswrd_xyz" "M" 1020.200