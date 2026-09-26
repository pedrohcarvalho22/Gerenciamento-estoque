#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <ctype.h>
#define tamanhoo 100

typedef struct{
    char nome[tamanhoo];
    int codigo;
    int quantidade;
    float preco;
    char categoria[tamanhoo]; 
} Produto;

void cadastrarProduto(Produto **produto, int *indice, int *tamanho);

void listarProdutos(Produto *produtos, int quantidade);

int pesquisarProduto(Produto *produtos, char nome[], int quantidade);

int pesquisarProduto2(Produto *produtos, char nome[], int quantidade, int po);

int pesquisarCodigo(Produto *produtos, int codigo, int quantidade);

int pesquisarCodigo2(Produto *produtos, int codigo, int quantidade, int po);

void alterarProduto(Produto *produtos, int quantidade);

void removerProduto(Produto *produtos, int *quantidade);

void entradaTexto(char nome[], int quantidade);

int entradaVerificadaInt();

float entradaVerificadaFloat();

Produto *criar();