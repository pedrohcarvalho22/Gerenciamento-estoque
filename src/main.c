#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <ctype.h>
#include "produto.h"
#include "estoque.h"

int main() {
    Produto *produtos=criar();
    int quantidade=0, tamanho=3, opcao, menu=1, opcaor;

    while (menu==1){
        printf("\n\nGerenciamento de estoque \n1)Cadastrar produto \n2)Listar produto \n3)Pesquisar produto \n4)Alterar produto \n5)Remover produto \n6)Entrada de estoque \n7)Saida de estoque \n8)Relatorio \n0)Sair \n\nDigite o numero da opcao que voce deseja executar: ");
        do{
            opcao=entradaVerificadaInt();
            if (opcao<0){
                printf("Digite um valor positivo: ");
            }
        }while(opcao<0);
            switch (opcao)
            {
            case 1:
                cadastrarProduto(&produtos, &quantidade, &tamanho);
                break;

            case 2:
                listarProdutos(produtos, quantidade);
                break;

            case 3:
                ;
                char nome[100];
                printf("\nDigite o nome do produto: ");
                entradaTexto(nome, sizeof(nome));
                int p=pesquisarProduto(produtos, nome, quantidade);
                if (p==-1){
                    printf("\nProduto nao encontrado\n");
                }
                else{
                    printf("\nProduto encontrado:\nPosicao: %d \nNome: %s \nCategoria: %s \nQuantidade: %d \nCodigo: %d \nPreco: %.2f\n", p+1, produtos[p].nome, produtos[p].categoria, produtos[p].quantidade, produtos[p].codigo, produtos[p].preco);
                }
                break;

            case 4:
                alterarProduto(produtos, quantidade);
                break;

            case 5:
                removerProduto(produtos, &quantidade);
                break;

            case 6:
                entradaEstoque(produtos, quantidade);
                break;

            case 7:
                saidaEstoque(produtos, quantidade);
                break;

            case 8:
                ;
                int menur=1;
                while(menur==1){
                    printf("\n\nRelatorios: \n1)Produto com maior estoque \n2)Produto com menor estoque \n3)Valor total do estoque \n4)Listar \n0)Voltar \n\nDigite o numero da opcao desejada: ");
                    do{
                        opcaor=entradaVerificadaInt();
                        if (opcaor<0){
                            printf("Digite um valor positivo: ");
                        }
                    }while(opcaor<0);
                    switch (opcaor){
                        case 1:
                            ;
                            if (quantidade==0){
                                printf("Nao ha produtos cadastrados");
                            }
                            else{
                                int po= maiorEstoque(produtos, quantidade);
                                printf("O produto de maior estoque eh o que esta na posicao %d, com nome %s e tem %d unidades no estoque", po+1, produtos[po].nome, produtos[po].quantidade);
                            }
                            break;

                        case 2:
                            ;
                            if (quantidade==0){
                                printf("Nao ha produtos cadastrados");
                            }
                            else{
                                int pos= menorEstoque(produtos, quantidade);
                                printf("O produto de menor estoque eh o que esta na posicao %d, com nome %s e tem %d unidades no estoque", pos+1, produtos[pos].nome, produtos[pos].quantidade);
                            }
                            break;
                        
                        case 3:
                            if (quantidade==0){
                                printf("Nao ha produtos cadastrados");
                            }
                            else{
                                printf("O valor de todos os itens do estoque da %.2f reais", valorEstoque(produtos, quantidade));
                            }
                            break;
                            
                            case 4:
                                if (quantidade==0){
                                    printf("Nao ha produtos cadastrados");
                                }
                                else{
                                    listarEstoque(produtos, quantidade);
                                }
                                break;
                            
                            case 0:
                                menur=0;
                                break;
                
                            default:
                                printf("Valor de opcao diferente dos disponiveis, tente um valor de 0 a 4\n");
                                break;
                        }
                    }
                
                break;
                

            case 0:
                menu=0;
                break;
            
            default:
                printf("Valor de opcao diferente dos disponiveis, tente um valor de 0 a 8\n");
                break;
            }
        }
        free(produtos);
        return 0;
    }
