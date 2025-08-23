#include <stdio.h>
int main(){
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
        if( a < b+c && b < c+a && c < b+a){
            printf("Os lados formam um triângulo\n");
            if(a == b == c){
                printf("É um triângulo equilátero\n");
            }
        }else{
            printf("Não temos um triangulo!\n");
        }
    return 0;
}