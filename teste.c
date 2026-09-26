#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <ctype.h>

void entradaTexto(char nome[], int tamanho){
    int inicio=0, i, c;
    while (1){
    fgets(nome, tamanho, stdin);
    if (strchr(nome, '\n') == NULL){
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Entrada invalida, tente novamente: ");
        continue;
    }
    nome[strcspn(nome, "\n")]='\0';
    while (nome[inicio] != '\0' && isspace((unsigned char)nome[inicio])){
        inicio++;
    }
    if (inicio > 0){
        memmove(nome, nome + inicio, strlen(nome + inicio) + 1);
    }
    if((nome[0] == '\0')){
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


typedef struct{
    char nome[100];
    int codigo;
    int quantidade;
    float preco;
    char categoria[100]; 
} Produto;

int main(){
    char nome[100], nome2[100];
    int i;
    float a;
    Produto *produtos, *temp;

    produtos = malloc(3*sizeof(Produto));
    if(!produtos){
        perror(NULL);
        printf("Erro na alocacao");
    }
    produtos[0].codigo=2;
    temp = realloc(produtos, 4*sizeof(Produto));
    if (temp != NULL) {
    produtos = temp;
    }
    else {
    printf("Erro na alocacao");
    }
    produtos[3].codigo=2;

    printf("Digite nome 1: ");

    entradaTexto(nome, sizeof(nome));

    printf("Digite um numero inteiro: ");

    i = entradaVerificadaInt();

    printf("Digite um numero decimal: ");

    a = entradaVerificadaFloat();

    printf("Digite nome 2: ");

    entradaTexto(nome2, sizeof(nome2));

    printf("O que foi lido: [%s]; [%d]; [%f]; [%s]", nome, i, a, nome2);

    return 0;
}