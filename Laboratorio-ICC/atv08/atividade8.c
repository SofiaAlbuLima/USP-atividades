#include <stdio.h>
int main(){
    float operando1, operando2, resultado;
    char sinal;
    scanf("%f %c %f", &operando1, &sinal, &operando2);

    switch(sinal){
        case '+': resultado = operando1 + operando2;
            break;
        case '-': resultado = operando1 - operando2;
            break;
        case '*': resultado = operando1 * operando2;
            break;
        case '/': resultado = operando1 / operando2;
            break;
    }
    printf("%.2f", resultado);
}