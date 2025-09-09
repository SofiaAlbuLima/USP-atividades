#include <stdio.h>

typedef struct{
        char nome[50];
        int populacao;
    } CIDADE ;

int main(){
    int n;
    scanf("%d", &n);

    if(n < 2 || n > 10){
        printf("n fora do intervalo.\n");
        return 1;
    }

    CIDADE cidades[n]; //array de structs

    for(int i=0; i<n; i++){
        scanf(" %[^\n]", cidades[i].nome);
        scanf(" %d", &cidades[i].populacao);

        if(cidades[i].populacao > 6000000){
            return 1;
        }
    }

    int maior = 0;

    for(int i=1; i<n; i++){
        if(cidades[i].populacao > cidades[maior].populacao){
            maior = i;
        }
    }

    printf(" %s %d", cidades[maior].nome, cidades[maior].populacao);
    return 0;
}