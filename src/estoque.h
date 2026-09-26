#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <ctype.h>

void entradaEstoque(Produto *produtos, int quantidade);

void saidaEstoque(Produto *produtos, int quantidade);

int maiorEstoque(Produto *produtos, int quantidade);

int menorEstoque(Produto *produtos, int quantidade);

float valorEstoque(Produto *produtos, int quantidade);

void listarEstoque(Produto *produtos, int quantidade);