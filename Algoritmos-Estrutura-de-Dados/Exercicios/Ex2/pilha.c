#include <stdio.h>
#include "Pilha.h"
#include "item.h"

typedef struct pilha{
    ITEM* item[TAM];
    int tamanho;
}PILHA;

PILHA* pilha_criar(void){
    PILHA* pilha = (PILHA*) malloc (sizeof(PILHA));
    if(pilha != NULL){
        pilha->tamanho = 0;
        return pilha;
    }
}

void pilha_apagar(PILHA** pilha){
    free(pilha);
}

bool pilha_vazia(PILHA* pilha){
    if(pilha != NULL && pilha->tamanho == 0){
        return true;
    }else{
        return false;
    }
}

bool pilha_cheia(PILHA* pilha){
    if(pilha->item != NULL && pilha->tamanho == TAM){
        return true;
    }else{
        return false;
    }
}

int pilha_tamanho(PILHA* pilha){
    if(pilha->tamanho != NULL){
        printf("tamanho: %d", pilha->tamanho);
    }
}

ITEM* pilha_topo(PILHA* pilha){
    if(pilha->tamanho != NULL){
        return pilha->item[pilha->tamanho];
    }
}

bool pilha_empilhar(PILHA* pilha, ITEM* item){
    if(!pilha_cheia(pilha) && pilha != NULL){
        pilha->item[pilha->tamanho] = item;
        pilha->tamanho++;
        return true;
    }else{
        return false;
    }
}

ITEM* pilha_desempilhar(PILHA* pilha){
    if(!pilha_vazia(pilha) && pilha != NULL){
        return item_apagar(pilha->item[pilha->tamanho]);    
    }
}