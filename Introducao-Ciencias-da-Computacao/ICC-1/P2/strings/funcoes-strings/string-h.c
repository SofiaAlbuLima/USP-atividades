#include <stdio.h>
#include <string.h>  
int main(){
    char string1[20];
    char string2[20];

    
    scanf(" %19[^\n]s", string1);
    scanf(" %19[^\n]s", string2);

    printf("-> string 1: %s\n", string1);
    printf("--> tamanho 1: %lu\n", strlen(string1));
    printf("-> string 2: %s\n", string2);
    printf("--> tamanho 2: %lu\n", strlen(string2));

    if(strcmp(string1, string2) == 0){
        printf("string 1 = string 2\n");
    }else if(strcmp(string1, string2) > 0){
        printf("string 1 > string 2\n");
    }else if(strcmp(string1, string2) < 0){
        printf("string 1 < string 2\n");
    }
}