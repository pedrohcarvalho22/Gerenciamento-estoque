#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <ctype.h>
#include "produto.h"
#include "estoque.h"

void cadastrarProduto(Produto **produto, int *indice, int *tamanho){

    Produto *temp;

    if (*indice == *tamanho){

        temp = realloc(*produto, (*tamanho + 1) * sizeof(Produto));

        if (!temp){
            perror("Erro na alocacao");
            return;
        }

        *produto = temp;
        *tamanho = *tamanho + 1;
    }

    printf("Digite o nome do produto %d: ", *indice + 1);

    entradaTexto((*produto)[*indice].nome,
                 sizeof((*produto)[*indice].nome));

    if (pesquisarProduto(*produto,
                          (*produto)[*indice].nome,
                          *indice) != -1){

        printf("\nProduto ja registrado");
    }
    else{

        do{
            printf("Digite o preco do produto %d: ", *indice + 1);

            (*produto)[*indice].preco = entradaVerificadaFloat();

            if ((*produto)[*indice].preco <= 0){
                printf("\nO preco tem que ser maior que 0: ");
            }

        }while ((*produto)[*indice].preco <= 0);


        do{
            printf("Digite a quantidade do produto %d registrado: ",
                   *indice + 1);

            (*produto)[*indice].quantidade = entradaVerificadaInt();

            if ((*produto)[*indice].quantidade <= 0){
                printf("\nA quantidade tem que ser maior que 0");
            }

        }while ((*produto)[*indice].quantidade <= 0);


        printf("Digite a categoria do produto %d: ",
               *indice + 1);

        entradaTexto((*produto)[*indice].categoria,
                     sizeof((*produto)[*indice].categoria));


        do{
            printf("Digite o codigo do produto %d: ",
                   *indice + 1);

            (*produto)[*indice].codigo = entradaVerificadaInt();

            if ((*produto)[*indice].codigo < 0){

                printf("O codigo tem que ser positivo: ");

            }
            else if (pesquisarCodigo(*produto,
                                      (*produto)[*indice].codigo,
                                      *indice) != -1){

                printf("Codigo ja em uso, tente outro valor: ");
            }

        }while (((*produto)[*indice].codigo < 0) ||
                (pesquisarCodigo(*produto,
                                 (*produto)[*indice].codigo,
                                 *indice) != -1));


        printf("Produto cadastrado\n");

        *indice = *indice + 1;
    }
}

    



void listarProdutos(Produto *produtos, int quantidade){
    int i;
    for (i=0; i<quantidade; i++){
        printf("\nProduto %d: \nNome: %s \nCategoria: %s \nQuantidade: %d \nCodigo: %d \nPreco: %.2f\n", i+1, produtos[i].nome, produtos[i].categoria, produtos[i].quantidade, produtos[i].codigo, produtos[i].preco);
    }
}

int pesquisarProduto(Produto *produtos, char nome[], int quantidade){
    int i, p=-1;
    for (i=0; i<quantidade; i++){
        if (_stricmp(nome, produtos[i].nome)==0){
            p=i;
            break;
        }
    }
    return p;
}

int pesquisarProduto2(Produto *produtos, char nome[], int quantidade, int po){
    int i, p=-1;
    for (i=0; i<quantidade; i++){
        if ((_stricmp(nome, produtos[i].nome)==0) && (i!=po)){
            p=i;
            break;
        }
    }
    return p;
}

int pesquisarCodigo(Produto *produtos, int codigo, int quantidade){
    int i, p=-1;
    for (i=0; i<quantidade; i++){
        if (codigo==produtos[i].codigo){
            p=i;
            break;
        }
    }
    return p;
}

int pesquisarCodigo2(Produto *produtos, int codigo, int quantidade, int po){
    int i, p=-1;
    for (i=0; i<quantidade; i++){
        if ((codigo==produtos[i].codigo) && (i!=po)){
            p=i;
            break;
        }
    }
    return p;
}

void alterarProduto(Produto *produtos, int quantidade){
    char nome[tamanhoo];
    char novonome[tamanhoo], novacategoria[tamanhoo];
    int novocodigo, novaquantidade;
    float novopreco;
    printf("\nDigite o nome do produto: ");
    entradaTexto(nome, sizeof(nome));
    int p = pesquisarProduto(produtos, nome, quantidade);
    if(p==-1){
            printf("\nProduto nao encontrado\n");
    }
    else{
        printf("Digite as informacoes do novo produto: ");
        printf("Digite o nome do novo produto: ");
        entradaTexto(novonome, sizeof(novonome));
        if(pesquisarProduto2(produtos, novonome, quantidade, p)!=-1){
            printf("\nProduto ja registrado");
        }
        else{
            do{
                printf("Digite o preco do novo produto: ");
                novopreco = entradaVerificadaFloat();
                if(novopreco<=0){
                    printf("\nO preco tem que ser maior que 0: ");
                }
            } while(novopreco<=0);
            do{
                printf("Digite a quantidade do novo produto registrado: ");
                novaquantidade = entradaVerificadaInt();
                if(novaquantidade<=0){
                    printf("\nA quantidade tem que ser maior que 0: ");
                }
            }while(novaquantidade<=0);
            printf("Digite a categotia do novo produto: ");
            entradaTexto(novacategoria, sizeof(novacategoria));
            do{
                printf("Digite o codigo do novo produto: ");
                novocodigo = entradaVerificadaInt();
                if(novocodigo<0){
                    printf("Codigo precisa ser positivo: ");
                }
                else if(pesquisarCodigo2(produtos, novocodigo, quantidade, p)!=-1){
                    printf("Codigo ja cadastrado em outro produto: ");
                }
            }while((novocodigo<0) || (pesquisarCodigo2(produtos, novocodigo, quantidade, p)!=-1));
            strcpy(produtos[p].nome,novonome);
            strcpy(produtos[p].categoria,novacategoria);
            produtos[p].preco = novopreco;
            produtos[p].quantidade=novaquantidade;
            produtos[p].codigo=novocodigo;
            printf("Produto alterado\n");
        }
    }
}
    



void removerProduto(Produto *produtos, int *quantidade){
    char nome[tamanhoo];
    int i, valor=*quantidade;
    printf("\nDigite o nome do produto: ");
    entradaTexto(nome, sizeof(nome));
    int p = pesquisarProduto(produtos, nome, *quantidade);
    if (p==-1){
        printf("\nProduto nao encontrado\n");
    }
    else{
        char nomeRemovido[tamanhoo];
        strcpy(nomeRemovido, produtos[p].nome);
        for (i=p; i<(valor-1);i++){
            produtos[i] = produtos[i+1];
        }
        *quantidade = *quantidade-1;
        printf("Produto de nome %s removido", nomeRemovido);
    }
}

void entradaTexto(char nome[], int tamanho){
    int inicio, c;
    while (1){
        inicio = 0;
        fgets(nome, tamanho, stdin);
        if (strchr(nome, '\n') == NULL){
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada invalida, tente novamente: ");
            continue;
        }
        nome[strcspn(nome, "\n")] = '\0';
        while (nome[inicio] != '\0' && isspace((unsigned char)nome[inicio])){
            inicio++;
        }
        if (inicio > 0){
            memmove(nome, nome + inicio, strlen(nome + inicio) + 1);
        }
        if (nome[0] == '\0'){
            printf("Entrada invalida, tente novamente: ");
            continue;
        }
        break;
    }
}

int entradaVerificadaInt(){
    long a;
    char nome[100], *fim;
    int c;

    while (1){

        fgets(nome, sizeof(nome), stdin);

        if (strchr(nome, '\n') == NULL){
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada invalida, tente novamente: ");
            continue;
        }

        errno = 0;
        a = strtol(nome, &fim, 10);

        if ((fim == nome) || ((*fim != '\n') && (*fim != '\0')) || (a > INT_MAX) || (a < INT_MIN) || (errno == ERANGE)){

            printf("Entrada invalida, tente novamente: ");
            continue;
        }

        return (int)a;
    }
}

float entradaVerificadaFloat(){
    float a;
    char nome[100], *fim;
    int c;
    while (1){

        fgets(nome, sizeof(nome), stdin);

        if (strchr(nome, '\n') == NULL){
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada invalida, tente novamente: ");
            continue;
        }

        errno = 0;
        a = strtof(nome, &fim);

        if ((fim == nome) || ((*fim != '\n') && (*fim != '\0')) || (a > FLT_MAX) || (a < -FLT_MAX) || (errno == ERANGE)){
            printf("Entrada invalida, tente novamente: ");
            continue;
        }

        return a;
    }
}

Produto *criar(){
    Produto *produtos;
    produtos = malloc(3*sizeof(Produto));
    if (!produtos){
        perror(NULL);
        printf("Erro na alocação");
    }
    return produtos;
}