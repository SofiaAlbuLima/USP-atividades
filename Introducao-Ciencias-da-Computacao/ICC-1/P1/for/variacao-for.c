#include <stdio.h>
int main(){
    int i,j;
    for(i = 0, j = 100; i + j >= 0; i++, j -= 2){
        printf("%d e %d\n", i, j);
    }
}