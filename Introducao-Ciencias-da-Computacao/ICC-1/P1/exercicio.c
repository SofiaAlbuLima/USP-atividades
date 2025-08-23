#include <stdio.h>
int main(){
    char nome[51];
    float nota;
    int faltas, atividades;

    scanf("%50s %f %d %d", nome, &nota, &faltas, &atividades);

    if(nota < 0 || nota > 10 || faltas < 0 || atividades < 0 || atividades > 5){
        printf("entrada inválida \n");
        return 1;
    }

    float nota_final;
    float nota_ajustada = 0;

    if(atividades >= 3 && faltas > 15){
        nota_ajustada = 0;
    } else if(atividades >= 3){
        nota_ajustada += 1;
    } else if(faltas > 15){
        nota_ajustada -= 1;
    } else{
        nota_ajustada = 0;
    }

    nota_final = nota + nota_ajustada;
    printf("nota final: %f\n", nota_final);

    printf("nome: %s \n", nome);
    printf("nota inicial: %f \n", nota);
    printf("nota ajustada: %f \n", nota_ajustada);
    printf("desempenho:");

    if(nota_final >= 9 && nota_final < 10.01){
        printf(" excelente\n");
    } else if(nota_final >= 7 && nota_final < 8.9){
        printf(" bom\n");
    } else if(nota_final >= 5 && nota_final < 6.9){
        printf(" regular\n");
    } else if(nota_final >= 0 && nota_final < 4.9){
        printf(" insuficiente\n");
    }
}