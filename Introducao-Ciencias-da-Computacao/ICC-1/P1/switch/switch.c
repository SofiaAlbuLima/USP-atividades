#include <stdio.h>
int main(){
    char a;
    scanf("%c", &a);
    switch(a){
        case 1: printf("um\n");
                break;
        case 2: printf("dois\n");
                break;
        case 3: printf("três\n");
                break;
        default: printf("nenhum\n");
                break;
    }

    return 0;
}