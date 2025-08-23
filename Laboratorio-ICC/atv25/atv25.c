#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s = (char *)malloc(10001 * sizeof(char));
    char *t = (char *)malloc(10001 * sizeof(char));
    scanf("%10000s", s);
    scanf("%10000s", t);

    int tam = strlen(t);
    int maior = 0;
    char *prefixo = NULL;

    for (int i = tam; i > 0; i--) {
        char *temp = (char *)malloc((i + 1) * sizeof(char));
        strncpy(temp, t, i);
        temp[i] = '\0';
        if (strstr(s, temp) != NULL) {
            maior = i;
            prefixo = temp;
            break;
        }
        free(temp);
    }

    if (maior == 0) {
        printf("0\n");
    } else {
        printf("%d %s\n", maior, prefixo);
        free(prefixo);
    }

    free(s);
    free(t);

    return 0;
}
