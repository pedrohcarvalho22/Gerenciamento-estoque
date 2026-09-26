#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <ctype.h>
#include "produto.h"
#include "estoque.h"

void entradaEstoque(Produto *produtos, int quantidade){
    int valor;
    char nome[tamanhoo];
    printf("\nDigite o nome do produto que voce quer adicionar unidades no estoque: ");
    entradaTexto(nome, sizeof(nome));
    int p=pesquisarProduto(produtos, nome, quantidade);
    if(p==-1){
        printf("\nProduto nao encontrado");
    }
    else{
        printf("\nDigite quantas unidades desse produto serao adicionadas no estoque: ");
        do{
            valor = entradaVerificadaInt();
            if(valor<=0){
                printf("O valor tem que ser maior que 0");
            }
        }while(valor<=0);
        produtos[p].quantidade = produtos[p].quantidade + valor;
        printf("\nForam adicionados %d unidades ao produto nomeado como %s, e agora no total tem %d", valor, nome, produtos[p].quantidade);
    }
}

void saidaEstoque(Produto *produtos, int quantidade){
    int valor;
    char nome[tamanhoo];
    printf("\nDigite o nome do produto que voce quer retirar unidades do estoque: ");
    entradaTexto(nome, sizeof(nome));
    int p=pesquisarProduto(produtos, nome, quantidade);
    if (p==-1){
        printf("\nProduto nao encontrado");
    }
    else{
        printf("\nDigite quantas unidades desse produto serao retiradas do estoque: ");
        do{
            valor = entradaVerificadaInt();
            if(valor<=0){
                printf("O valor tem que ser maior que 0");
            }
        }while(valor<=0);
            if (valor>produtos[p].quantidade){
                printf("\nNao eh possivel fazer essa saida do estoque pois a quantidade desejada, %d, eh maior do que a presente no estoque, %d", valor, produtos[p].quantidade);
            }
            else{
                produtos[p].quantidade = produtos[p].quantidade-valor;
                printf("\nForam removidos %d itens do estoque do produto %s, agora restam %d", valor, produtos[p].nome, produtos[p].quantidade);
            }
    }
}

int maiorEstoque(Produto *produtos, int quantidade){
    int i, maior=0, posicao=0;
    for(i=0; i<quantidade; i++){
        if(produtos[i].quantidade>maior){
            maior = produtos[i].quantidade;
            posicao = i;
        }
    }
    return posicao;
}

int menorEstoque(Produto *produtos, int quantidade){
    int i, menor=produtos[0].quantidade, posicao=0;
    for(i=0; i<quantidade; i++){
        if(produtos[i].quantidade<=menor){
            menor = produtos[i].quantidade;
            posicao = i;
        }
    }
    return posicao;
}

float valorEstoque(Produto *produtos, int quantidade){
    int i;
    float total=0;
    for(i=0;i<quantidade;i++){
        total = total + (produtos[i].preco*produtos[i].quantidade);
    }
    return total;
}

void listarEstoque(Produto *produtos, int quantidade){
    int i;
    for(i=0; i<quantidade; i++){
        printf("\n%d)%s: %d unidades;", i+1, produtos[i].nome, produtos[i].quantidade);
    }
}