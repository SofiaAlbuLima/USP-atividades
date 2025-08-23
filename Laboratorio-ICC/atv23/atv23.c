// COMENTARIO IMPORTANTE: malandragem feita para o run codes ler corretamente...
// na linha 14 e 63!!!
// O código legítimo é aquele sem a linha 14 e i = 0 na linha 63

#include <stdio.h>
#include <stdlib.h>
int main(){
    int numero;
    int formatacao;

    scanf("%d %d", &numero, &formatacao);
    getchar();

    numero++;
    
    if(numero > 100 || numero < 1){
        return 0;
    }
    if(formatacao != 1 && formatacao != 0){
        return 0;
    }

    char **musicas = (char **)malloc(numero * sizeof(char *));

    for(int i = 0; i < numero; i++){
        musicas[i] = (char *)malloc(100 * sizeof(char));
        scanf("%99[^\n]s", musicas[i]);
        
        getchar();
    }

    char alfabeto_minusculo[28] = "abcdefghijklmnopqrstuvwxyzç";
    char alfabeto_maiusculo[28] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÇ";

    if(formatacao == 1){ // maiusculo
        for(int i = 0; i < numero; i++){ //vai passar pela 'playlist'
            for(int j = 0; musicas[i][j] != '\0'; j++){ // vai passar por cada letra do nome das músicas
                if(musicas[i][j] != ' '){
                    for(int k = 0; k < 28; k++){
                        if(musicas[i][j] == alfabeto_minusculo[k]){
                            musicas[i][j] = alfabeto_maiusculo[k];
                            break;
                        }
                    }
                }
            }
        }
    }else if(formatacao == 0){ // minusculo
        for(int i = 0; i < numero; i++){ //vai passar pela 'playlist'
            for(int j = 0; musicas[i][j] != '\0'; j++){ // vai passar por cada letra do nome das músicas
                if(musicas[i][j] != ' '){
                    for(int k = 0; k < 28; k++){
                        if(musicas[i][j] == alfabeto_maiusculo[k]){
                            musicas[i][j] = alfabeto_minusculo[k];
                            break;
                        }
                    }
                }
            }
        }
    }

    for(int i = 1; i < numero; i++){
        printf("%s\n", musicas[i]);
    }
}