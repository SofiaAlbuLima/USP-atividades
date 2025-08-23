#include <stdio.h>
int main(){
    long long int num1, num2, resultado;
    int paridade1, paridade2, paridadeR;

    scanf("%lld %lld", &num1, &num2);

    paridade1 = num1 % 2 == 0;
    paridade2 = num2 % 2 == 0;

    if(paridade1 == paridade2){
        resultado = num1 * num2;
    } else{
        resultado = num1 + num2;
    }
    
    paridadeR = resultado % 2 == 0;

    switch(paridade1){
        case 1 : printf("O primeiro número é par\n");
            break;
        case 0 : printf("O primeiro número é ímpar\n");
            break;
    }
    switch(paridade2){
        case 1 : printf("O segundo número é par\n");
            break;
        case 0 : printf("O segundo número é ímpar\n");
            break;
    }
    printf("O resultado é %lld", resultado);
    switch(paridadeR){
        case 1 : printf(",que é par\n");
            break;
        case 0 : printf(",que é ímpar\n");
            break;
    }
}