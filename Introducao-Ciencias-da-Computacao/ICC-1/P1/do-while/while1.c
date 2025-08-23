#include <stdio.h>
int main(){
    float numeroA, numeroB, resultado;
    char operador;

    do{
        scanf("%f %c %f", &numeroA, &operador,&numeroB);
    }while(operador != '+' && operador != '-' && operador != '*' && operador != '/');

    switch(operador){
        case '+': resultado = numeroA + numeroB;
            break;
        case '-': resultado = numeroA - numeroB;
            break;
        case '*': resultado = numeroA * numeroB;
            break;
        case '/': resultado = numeroA / numeroB;
            break;
    }
    printf("O resultado de %.2f %c %.2f é %.2f\n", numeroA, operador,numeroB, resultado);
}