#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "restaurante.h"


//------------------------SALÃO------------------------//


// Adiciona um prato a lista de pedidos pendentes
void adicionar_salao(No **cabeca, int novo_dado){
    No *novo_no = malloc(sizeof(No));
    novo_no->dado = novo_dado;
    novo_no->proximo = NULL;

    if(*cabeca == NULL){
        novo_no->anterior = NULL;
        *cabeca = novo_no;
    }

    else{
        No *aux = *cabeca;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }

        aux->proximo = novo_no; 
        novo_no->anterior = aux; 
    }
}


// Remove o primeito prato da lista de pedidos pendentes
void remover_inicio(No **cabeca){
    if(*cabeca == NULL){
        printf("\n-> A lista de pedidos está vazia!\n");
        return;
    }

    No *temp = *cabeca;
    *cabeca = (*cabeca)->proximo;

    if(*cabeca != NULL){
        (*cabeca)->anterior = NULL;
    }

    free(temp);
}


// Remove o último prato da lista de pedidos pendentes
void remover_fim(No **cabeca){
    if(*cabeca == NULL){
        printf("\n-> A lista de pedidos está vazia!\n");
        return;
    }

    No *aux = *cabeca;
    while(aux->proximo != NULL){
        aux = aux->proximo;

    }

    No *temp = aux;
    aux = aux->anterior; 
    if(aux == NULL){
        *cabeca = NULL;
    }

    else{
        aux->proximo = NULL;
    }

    free(temp);
}


// Remove um prato que esteja no meio da lista de pedidos pendentes
void remover_salao(No **cabeca, int posicao){
    if(*cabeca == NULL){
        printf("\n-> A lista de pedidos está vazia!\n");
        return;
    }

    if(posicao < 0){
        printf("\n-> Posição inválida!\n");
        return;
    }

    No *aux = *cabeca;
    int cont = 0;

    while(aux != NULL && cont < posicao){
        aux = aux->proximo;
        cont++;
    }

    if(aux == NULL){
        printf("\n-> Posição inválida!\n");
        return;
    }

    else if(aux == *cabeca){
        remover_inicio(cabeca);
        printf("\n-> Pedido removido.\n");
        return;
    }

    else if(aux->proximo == NULL){
        remover_fim(cabeca);
        printf("\n-> Pedido removido.\n");
        return;
    }

    else{
        aux->anterior->proximo = aux->proximo;
        aux->proximo->anterior = aux->anterior;
        printf("\n-> Pedido removido.\n");
    }

    free(aux);
}


// Lista todos os pedidos pendentes no salão
void listar_salao(No *cabeca) {
    if(cabeca == NULL){
        printf("\n-> A lista de pedidos está vazia!\n");
        return;
    }

    No *aux = cabeca;
    printf("\n");
    while(aux != NULL){
        printf("%d | ", aux->dado);
        aux = aux->proximo;
    }

    printf("\n");
}


//-----------------------COZINHA-----------------------//


// Inicializa a fila de processamento
void inicializar_fila(Fila* fila){
    fila->tamanho = 0;
}


// Verifica se a fila de processamento está vazia
int fila_vazia(Fila* fila){
  return fila->tamanho == 0;
}


// Verifica se a fila de processamento está cheia
int fila_cheia(Fila* fila){
  return fila->tamanho == MAX;
}


// Transfere o primeiro pedido da lista de pendentes para o processamento
void adicionar_cozinha(No **cabeca, Fila* fila){
    if(fila_cheia(fila)){
        printf("\n-> A fila de processamento está cheia!\n");
    }

    else{
        if(*cabeca == NULL){
            printf("\n-> A lista de pedidos está vazia!\n");
            return;
        }

        No *temp = *cabeca;
        int valor = temp->dado;
        *cabeca = (*cabeca)->proximo;

        if(*cabeca != NULL){
            (*cabeca)->anterior = NULL;
        }

        free(temp);

        fila->dados[fila->tamanho] = valor;
        fila->tamanho++;
    }
}


// Lista todos os pedidos em processamento na cozinha
void listar_cozinha(Fila* fila){
    if(fila_vazia(fila)){
        printf("\n-> A fila de processamento está vazia!\n");
    }

    else{
        printf("\n");
        
        for(int i = 0; i < fila->tamanho; i++){
            printf("%d | ", fila->dados[i]);
        }

        printf("\n");
    }
}