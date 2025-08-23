#include <stdio.h>
int main(){
    int tesouro;
    scanf("%d", &tesouro);
    printf("Valor inicial do tesouro: %d\n", tesouro);

    void* mapa = &tesouro;
    // p é um ponteiro para um inteiro, no qual seu conteudo é um endereço do 'tesouro'
    printf("Valor do tesouro usando mapa: %d\n", *(int*)mapa);

    *(int*)mapa += 10;

    printf("Valor do tesouro usando mapa depois de adicionarmos 10 moedas: %d\n", *(int*)mapa);

    void** mapa_do_mapa = &mapa;
    
    printf("Valor do tesouro usando mapa para o mapa: %d\n", **(int**)mapa_do_mapa);
    
    **(int**)mapa_do_mapa += 10;
    
    printf("Valor do tesouro usando mapa para o mapa depois de adicionarmos 10 moedas: %d\n", **(int**)mapa_do_mapa);

}