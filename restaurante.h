#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#define MAX 100

struct no{
  int dado;
  struct no *proximo;
  struct no *anterior;
};

typedef struct no No;

typedef struct{
    int dados[MAX];
    int tamanho;
}Fila;

void adicionar_salao(No **cabeca, int pedido);
void remover_salao(No **cabeca, int posicao);
void listar_salao(No *cabeca);

void inicializar_fila(Fila* fila);
void adicionar_cozinha(No **cabeca, Fila* fila);
void listar_cozinha(Fila* fila);

#endif