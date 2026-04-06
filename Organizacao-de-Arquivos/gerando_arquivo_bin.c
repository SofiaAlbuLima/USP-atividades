#include <stdio.h>

int main(void){
    /* Gerando um arquivo Binário em C:
      | Para gerar um arquivo binário em C, você utiliza a função fwrite. A grande vantagem é que ela pega a
      | sua struct inteira da memória e "carimba" diretamente no arquivo, sem precisar converter nada para texto.
    */

    FILE *bin_fp = fopen("dados.bin", "wb");

    if (bin_fp == NULL) {
        printf("Erro ao criar arquivo binário!\n");
        return 1;
    }

    

}