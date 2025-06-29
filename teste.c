#include <stdio.h> 
#include <string.h>
int main(){
    int c[10], i;
    for (i = 0; i < 100; i++){
        c[i] = i;
        printf("%d", c[i]);
    }
}