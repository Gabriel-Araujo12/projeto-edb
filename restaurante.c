#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "restaurante.h"


//------------------------SALÃO------------------------//


// Adiciona um prato ao pedido
void adicionar_prato(Pedido *pedido, int id){
    if(pedido->qntd == MAX){
        printf("\n-> Não é possível adicionar mais pratos.\n");
    }

    else{
        pedido->pratos[pedido->qntd] = id;
        pedido->qntd++;
    }
}


// Adiciona um pedido a lista de pedidos pendentes
void adicionar_pedido(No **cabeca, Pedido pedido){
    No *novo_no = malloc(sizeof(No));
    novo_no->pedido = pedido;
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


// Remove um prato de um pedido na lista de pendentes
void remover_prato(No **cabeca, int posicao){
    No *aux = *cabeca;
    int cont = 0;

    while(aux != NULL && cont < posicao){
        aux = aux->proximo;
        cont++;
    }

    if(aux == NULL){
        printf("\n-> Pedido inválido.\n");
        return;
    }

    int pos_prato;
    printf("\nQual a posição do prato que deseja remover? ");
    scanf("%d", &pos_prato);
    pos_prato = pos_prato - 1;

    if(pos_prato < 0 || pos_prato >= aux->pedido.qntd){
        printf("\n-> Prato inválido.\n");
        return;
    }

    for(int i = pos_prato; i < aux->pedido.qntd - 1; i++){
        aux->pedido.pratos[i] = aux->pedido.pratos[i + 1];
    }

    aux->pedido.qntd--;
    
    printf("\n-> Prato removido do pedido.\n");
}


// Lista todos os pedidos pendentes no salão
void listar_salao(No *cabeca) {
    if(cabeca == NULL){
        printf("\n-> A lista de pedidos está vazia.\n");
        return;
    }

    No *aux = cabeca;
    while(aux != NULL){
        printf("\n|");
        for(int i = 0; i < aux->pedido.qntd; i++){
            printf("| %d |", aux->pedido.pratos[i]);
        }

        printf("|\n");
        aux = aux->proximo;
    }
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
void processar_pedido(No **cabeca, Fila* fila){
    if(fila_cheia(fila)){
        printf("\n-> A fila de processamento está cheia.\n");
    }

    else{
        if(*cabeca == NULL){
            printf("\n-> A lista de pedidos está vazia.\n");
            return;
        }

        No *temp = *cabeca;
        *cabeca = (*cabeca)->proximo;

        if(*cabeca != NULL){
            (*cabeca)->anterior = NULL;
        }

        for(int i = 0; i < temp->pedido.qntd; i++){
            fila->dados[fila->tamanho] = temp->pedido.pratos[i];
            fila->tamanho++;
        }

        printf("\n-> Pedido processado.\n");
        free(temp);
    }
}


// Lista todos os pedidos em processamento na cozinha
void listar_cozinha(Fila* fila){
    if(fila_vazia(fila)){
        printf("\n-> A fila de processamento está vazia.\n");
    }

    else{
        printf("\n|");

        for(int i = 0; i < fila->tamanho; i++){
            printf("| %d |", fila->dados[i]);
        }

        printf("|\n");
    }
}