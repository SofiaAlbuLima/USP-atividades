#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função opcional para remover espaços extras no início e fim (se quiser usar)
void trim(char *str) {
    char *start = str;
    while (*start == ' ') start++;
    char *end = str + strlen(str) - 1;
    while (end > start && (*end == ' ' || *end == '\n')) end--;
    *(end + 1) = '\0';
    memmove(str, start, end - start + 2);
}

int main() {
    int numero_de_livros;
    scanf("%d", &numero_de_livros);
    getchar();

    if (numero_de_livros < 0 || numero_de_livros > 100) return 0;

    char **titulos = (char **)malloc(numero_de_livros * sizeof(char *));
    char **autores = (char **)malloc(numero_de_livros * sizeof(char *));
    int *anos = (int *)malloc(numero_de_livros * sizeof(int));
    int *repeticoes = (int *)malloc(numero_de_livros * sizeof(int));

    for (int i = 0; i < numero_de_livros; i++) {
        titulos[i] = (char *)malloc(100 * sizeof(char));
        autores[i] = (char *)malloc(50 * sizeof(char));
        repeticoes[i] = 1;

        scanf(" %99[^,], %49[^,], %d", titulos[i], autores[i], &anos[i]);
        getchar();

        trim(titulos[i]);
        trim(autores[i]);

        for (int j = 0; j < i; j++) {
            if (strcmp(titulos[i], titulos[j]) == 0 &&
                strcmp(autores[i], autores[j]) == 0 &&
                anos[i] == anos[j]) {
                repeticoes[j]++;
                repeticoes[i] = 0;
                break;
            }
        }
    }

    printf("Catalogo de Livros:\n");

    int numero_livro = 1;
    int livros_distintos = 0;

    // Conta quantos livros distintos existem (com repeticoes[i] != 0)
    for (int i = 0; i < numero_de_livros; i++) {
        if (repeticoes[i] != 0) {
            livros_distintos++;
        }
    }

    int contagem = 0;
    for (int i = 0; i < numero_de_livros; i++) {
        if (repeticoes[i] != 0) {
            printf("Livro %d:\n", numero_livro++);
            printf("Titulo: %s\n", titulos[i]);
            printf("Autor: %s\n", autores[i]);
            printf("Ano: %d\n", anos[i]);
            printf("Quantidade: %d\n", repeticoes[i]);

            contagem++;
            if (contagem < livros_distintos) {
                printf("\n"); // imprime quebra de linha entre livros
            }
        }
    }


    for (int i = 0; i < numero_de_livros; i++) {
        free(titulos[i]);
        free(autores[i]);
    }
    free(titulos);
    free(autores);
    free(anos);
    free(repeticoes);

    return 0;
}
