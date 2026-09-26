📦 Sistema de Gerenciamento de Estoque

Projeto desenvolvido em C com o objetivo de praticar conceitos fundamentais da linguagem por meio de um sistema de gerenciamento de estoque executado no terminal.

O sistema simula o controle de produtos de uma pequena loja, permitindo cadastrar e administrar informações dos produtos e realizar operações relacionadas ao estoque.

🖥️ Funcionalidades

O sistema permite:

Cadastrar produtos;
Listar produtos;
Pesquisar produtos pelo nome;
Pesquisar produtos pelo código;
Alterar informações dos produtos;
Remover produtos;
Realizar entrada de estoque;
Realizar saída de estoque;
Gerar relatórios do estoque;
Validar entradas fornecidas pelo usuário;
Gerenciar dinamicamente a memória utilizada pelos produtos.
📋 Informações dos produtos

Cada produto possui:

Nome;
Código;
Categoria;
Preço;
Quantidade em estoque.
🛠️ Conceitos de C praticados

Durante o desenvolvimento foram praticados principalmente:

struct;
Arrays;
Arrays de struct;
Funções;
Parâmetros;
Ponteiros;
Ponteiros para ponteiros;
Passagem de parâmetros;
Strings;
fgets();
strtol();
strtof();
Validação de entrada;
Modularização;
Arquivos .c e .h;
malloc();
realloc();
free().
🧩 Organização do projeto
Gerenciamento estoque/
│
├── src/
│   ├── main.c
│   ├── produto.c
│   ├── produto.h
│   ├── estoque.c
│   └── estoque.h
│
├── output/
│   └── main.exe
│
├── .vscode/
│   ├── tasks.json
│   └── launch.json
│
├── .gitignore
└── README.md

O executável gerado na pasta output/ não deve ser enviado ao GitHub, pois está incluído no .gitignore.

🧠 Memória dinâmica

O projeto inicialmente utilizava um array com capacidade fixa.

Durante o desenvolvimento, essa abordagem foi substituída por memória dinâmica, utilizando:

malloc()

para realizar a alocação inicial,

realloc()

para aumentar a capacidade quando necessário,

e:

free()

para liberar a memória ao finalizar o programa.

A quantidade de produtos e a capacidade disponível são tratadas separadamente.

✅ Validação de entradas

O sistema possui funções específicas para validar diferentes tipos de entrada:

int entradaVerificadaInt();
float entradaVerificadaFloat();
void entradaTexto(char texto[], int tamanho);

As entradas numéricas utilizam fgets() junto com strtol() e strtof() para verificar se os valores fornecidos podem ser convertidos corretamente.

As entradas de texto também utilizam fgets(), com tratamento de quebra de linha, espaços iniciais, entradas vazias e linhas maiores que o limite definido.

▶️ Como executar

O projeto foi desenvolvido utilizando GCC e Visual Studio Code.

No VS Code, a execução pode ser realizada utilizando a configuração do projeto.

Também é possível compilar manualmente com o GCC:

gcc src/main.c src/produto.c src/estoque.c -o output/main.exe

Depois, o executável poderá ser executado normalmente.

🎯 Objetivo do projeto

Este projeto foi desenvolvido como uma forma de praticar e consolidar conhecimentos de programação em C.

A prioridade durante o desenvolvimento foi compreender os conceitos utilizados e aplicá-los gradualmente em uma aplicação prática, em vez de adicionar funcionalidades apenas para aumentar a complexidade do sistema.

📚 Status

Projeto acadêmico e de portfólio em desenvolvimento durante meus estudos de Ciência da Computação.

O projeto foi desenvolvido inicialmente com foco em estruturas, funções, modularização, validação de entradas e gerenciamento dinâmico de memória.

👨‍💻 Autor

Pedro Henrique Carvalho