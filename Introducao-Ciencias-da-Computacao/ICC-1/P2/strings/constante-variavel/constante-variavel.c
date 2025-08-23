#include <stdio.h>
int main(){
    char *string_constante = "string constante!";
    printf("%s\n\n", string_constante);

    char string_variavel[20] = "sofia"; // 5 chars + /0
    printf("%s\n", string_variavel);

    string_variavel[0] = 'S'; //mudança individual de char
    printf("variavel atualizada: %s\n", string_variavel);

    scanf("%19s", string_variavel);
    printf("variavel atualizada com scanf: %s\n", string_variavel);

    while (getchar() != '\n'); //evitar problemas com o '\n' pendurado

    fgets(string_variavel, sizeof(string_variavel), stdin);
    printf("variavel atualizada com fgets: %s\n", string_variavel);
}