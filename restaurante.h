#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#define MAX 100

// Define a estrutura de um pedido
typedef struct{
  int pratos[MAX];
  int qntd;
}Pedido;

// Define a lista de pedidos pendentes
struct no{
  Pedido pedido;
  struct no *proximo;
  struct no *anterior;
};

typedef struct no No;

// Define a fila de pedidos em processamento
typedef struct{
  int dados[MAX];
  int tamanho;
}Fila;

// Funções disponíveis para o salão
void adicionar_prato(Pedido *pedido, int id);
void adicionar_pedido(No **cabeca, Pedido pedido);
void remover_prato(No **cabeca, int posicao);
void listar_salao(No *cabeca);

// Funções disponíveis para a cozinha
void inicializar_fila(Fila* fila);
void processar_pedido(No **cabeca, Fila* fila);
void listar_cozinha(Fila* fila);

#endif