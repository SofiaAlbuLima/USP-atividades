#include <stdio.h>
#include <string.h>

int main(void){
    /* Aprendendo fgets
        | Usado para ler uma linha inteira (ou uma quantidade específica de caracteres) de um arquivo ou da entrada padrão (stdin)
        -> Caracteríscas: 
            - Muito Seguro (evita buffer overflow)
        -> Sintaxe:
            char *fgets(char *str, int n, FILE *fp);
            - str: Onde o texto lido será guardado (um array de char)
            - n: O tamanho máximo a ser lido (incluindo o caractere nulo \0)
            - fp: O ponteiro para o arquivo (ou stdin)
    */

    FILE *fp = fopen("entradas/declaracao.txt", "r");
    char linha[100];

    if(fp != NULL){ //se fopen der errado, fp será nulo!

        //nosso fgets vai ler até 99 caracteres ou até o primeiro "\n"
        if(fgets(linha, 100, fp) != NULL){
            printf("\nConteudo lido: %s\n", linha);
        }
        fclose(fp);
    }

    /* Aprendendo strtok
        | Serve para dividir uma string em partes menores, chamadas de "tokens", baseando-se em 
        | caracteres separadores (delimitadores) que você escolhe (como espaços, vírgulas ou pontos)
        -> Caracteríscas: 
            - Faz parte da biblioteca string.h
            - É uma função que guarda o estado internamente (ela tem uma memória própria de onde parou)
                - Primeira chamada: Você passa a string original. Ela encontra o primeiro delimitador e o substitui por um caractere nulo (\0). Ela retorna o endereço do início do primeiro pedaço.
                - Chamadas seguintes: Você passa NULL no primeiro argumento. Isso diz à função: "continue de onde você parou na última vez".
            - Ela modifica a string original: O strtok coloca \0 no lugar dos delimitadores. Se você precisar da string original intacta depois, faça uma cópia com strcpy antes
            - Não use com strings constantes: Se você fizer strtok("Texto Fixo", " "), o programa vai travar (Segmentation Fault), pois strings literais são somente leitura
            - Múltiplos delimitadores: Se você passar ", ." como delimitador, a função vai tratar vírgula, espaço e ponto como separadores simultaneamente
        -> Sintaxe:
            char *strtok(char *str, const char *delim);
            - str: A string que você quer dividir (na primeira chamada) ou NULL (nas chamadas seguintes)
            - delim: Uma string contendo todos os caracteres que devem ser tratados como separadores
    */

    char *token;

    // 1ª chamada: passa a string original
    token = strtok(linha, " ");

    while(token != NULL){
        printf("Token: %s\n", token);

        // Chamadas seguintes: passa NULL
        token = strtok(NULL, " ");
    }

    fclose(fp);
    return 0;
}