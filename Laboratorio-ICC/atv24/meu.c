#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int numero_de_livros;
    scanf("%d", &numero_de_livros);
    getchar();
    
    if(numero_de_livros > 100 || numero_de_livros < 0){
        return 0;
    }
    
    char**titulos = (char**)malloc(numero_de_livros * sizeof(char*));
    char**autores = (char**)malloc(numero_de_livros * sizeof(char*));
    int*anos = (int*)malloc(numero_de_livros * sizeof(int));
    int*repeticao_do_livro = (int*)malloc(numero_de_livros * sizeof(int));

    for(int i = 0; i < numero_de_livros; i++){
        titulos[i] = (char *)malloc(100 * sizeof(char));
        autores[i] = (char *)malloc(50 * sizeof(char));
        repeticao_do_livro[i] = 1;
        scanf(" %99[^,], %49[^,], %4d", titulos[i], autores[i], &anos[i]);
        getchar();

        if(i > 0){ // i = 1; //j = 0
            for(int j = 0; j < i; j++){ //compara o livro recém determinado com os anteriores
                if(strcmp(titulos[i], titulos[j]) == 0 && strcmp(autores[i], autores[j]) == 0 && anos[i] == anos[j]){
                    repeticao_do_livro[i]++;
                    repeticao_do_livro[j] = 0;
                }
            }
        }
    }

    printf("Catalogo de Livros:\n");
    for(int i = 0; i < numero_de_livros; i++){
        if(repeticao_do_livro[i] != 0){
        printf("Livro %d:\n", i+1);
        printf("Titulo: %s\n", titulos[i]);
        printf("Autor: %s\n", autores[i]);
        printf("Ano: %d\n", anos[i]);
        printf("Quantidade: %d\n\n", repeticao_do_livro[i]);
        }
    }

    free(titulos);
    free(autores);
    free(anos);
    free(repeticao_do_livro);

    return 0;
}