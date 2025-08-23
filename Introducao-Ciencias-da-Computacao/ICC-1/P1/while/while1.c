#include <stdio.h>
int main(){
    int num;
    scanf("%d", &num);
    int fat = num;
    int i = num - 1;
    while(i > 0){
        fat *= i;
        printf("i = %d e fatorial = %d e num = %d\n", i, fat, num);
        i--;
    }
}

