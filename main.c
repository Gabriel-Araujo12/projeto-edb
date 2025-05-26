#include <stdio.h>
#include "restaurante.h"

int main(){
    int num;
    No *cabeca = NULL;
    Fila fila;
    inicializar_fila(&fila);

        do{
        printf("\nEscolha uma das opções abaixo: \n");
        printf("1 -> Adicionar Pedido\n");
        printf("2 -> Processar Pedido\n");
        printf("3 -> Remover Pedido\n");
        printf("4 -> Listar Pedidos Pendentes\n");
        printf("5 -> Listar Pedidos em Processamento\n");
        printf("6 -> Sair\n");
        printf("Qual a opção desejada: ");
        scanf("%d", &num);

        if(num == 1){
            do{
                printf("\nEscolha uma das opções do cardápio: \n");
                printf("1 -> Entradas\n");
                printf("2 -> Pratos Principais\n");
                printf("3 -> Sobremesas\n");
                printf("4 -> Finalizar pedido\n");
                printf("Qual a opção desejada: ");
                scanf("%d", &num);

                if(num == 1){
                    printf("\n1 -> Sopa de Cebola\n");
                    printf("2 -> Salada Caesar\n");
                    printf("3 -> Bruschetta\n");
                    printf("4 -> Carpaccio de Carne\n");
                    printf("5 -> Camarão ao Alho\n");
                    printf("Qual a entrada desejada? ");
                    scanf("%d", &num);

                    if(num == 1){
                        adicionar_salao(&cabeca, 11);
                        printf("\n-> Prato adicionado. \n");
                    }

                    else if(num == 2){
                        adicionar_salao(&cabeca, 12);
                        printf("\n-> Prato adicionado. \n");
                    }

                    else if(num == 3){
                        adicionar_salao(&cabeca, 13);
                        printf("\n-> Prato adicionado. \n");
                    }

                    else if(num == 4){
                        adicionar_salao(&cabeca, 14);
                        printf("\n-> Prato adicionado. \n");
                        num = 0;
                    }

                    else if(num == 5){
                        adicionar_salao(&cabeca, 15);
                        printf("\n-> Prato adicionado. \n");
                    }

                    else{
                        printf("\n-> Opção inválida. \n");
                    }
                }

                else if(num == 2){
                    printf("\n1 -> Lasanha à Bolonhesa\n");
                    printf("2 -> Filé Mignon com Fritas\n");
                    printf("3 -> Frango Grelhado com Legumes\n");
                    printf("4 -> Bacalhau à Gomes de Sá\n");
                    printf("5 -> Risoto de Cogumelos\n");
                    printf("Qual o prato principal desejado? ");
                    scanf("%d", &num);

                    if(num == 1){
                        adicionar_salao(&cabeca, 21);
                        printf("\n-> Prato adicionado. \n");
                    }

                    else if(num == 2){
                        adicionar_salao(&cabeca, 22);
                        printf("\n-> Prato adicionado. \n");
                    }

                    else if(num == 3){
                        adicionar_salao(&cabeca, 23);
                        printf("\n-> Prato adicionado. \n");
                    }

                    else if(num == 4){
                        adicionar_salao(&cabeca, 24);
                        printf("\n-> Prato adicionado. \n");
                        num = 0;
                    }

                    else if(num == 5){
                        adicionar_salao(&cabeca, 25);
                        printf("\n-> Prato adicionado. \n");
                    }

                    else{
                        printf("\n-> Opção inválida. \n");
                    }
                }

                else if(num == 3){
                    printf("\n1 -> Tiramisu\n");
                    printf("2 -> Cheesecake de Frutas Vermelhas\n");
                    printf("3 -> Mousse de Chocolate\n");
                    printf("4 -> Pudim de Leite\n");
                    printf("5 -> Sorvete de Baunilha com Calda de Morango\n");
                    printf("Qual a sobremesa desejada? ");
                    scanf("%d", &num);

                    if(num == 1){
                        adicionar_salao(&cabeca, 31);
                        printf("\n-> Prato adicionado. \n");
                    }

                    else if(num == 2){
                        adicionar_salao(&cabeca, 32);
                        printf("\n-> Prato adicionado. \n");
                    }

                    else if(num == 3){
                        adicionar_salao(&cabeca, 33);
                        printf("\n-> Prato adicionado. \n");
                    }

                    else if(num == 4){
                        adicionar_salao(&cabeca, 34);
                        printf("\n-> Prato adicionado. \n");
                        num = 0;
                    }

                    else if(num == 5){
                        adicionar_salao(&cabeca, 35);
                        printf("\n-> Prato adicionado. \n");
                    }

                    else{
                        printf("\n-> Opção inválida. \n");
                    }
                }

                else if(num == 4){
                    printf("\n-> Finalizando pedido... \n");
                }

                else{
                    printf("\n-> Opção inválida. \n");
                }
            }while(num != 4);
        }

        else if(num == 2){
            adicionar_cozinha(&cabeca, &fila);
            printf("\n-> Pedido processado.\n");
        }

        else if(num == 3){
            printf("\nQual a posição do prato que deseja remover? ");
            scanf("%d", &num);
            num = num - 1;
            remover_salao(&cabeca, num);
        }

        else if(num == 4){
            listar_salao(cabeca);
        }

        else if(num == 5){
            listar_cozinha(&fila);
        }

        else if(num < 1 || num > 6){
            printf("\n-> Opção inválida \n");
        }

    }while(num != 6);
}