#include <stdlib.h>
#include <stdio.h>

// Faça um programa em C para manipular listas lineares usando alocação encadeada
// que de uma Lista textual para primeiramente escolher a estrutura de
// dados a ser manipulada e, em seguida, realizar operações nessa estrutura de dados.
// Todas as estruturas de dados devem armazenar números inteiros e suportar repetições
// de valores. As seguintes estruturas de dados e operações devem ser implementadas:

// Lista simplesmente encadeada sem nó cabeça ordenada: busca, inserção e remoção ;
// Lista circular simplesmente encadeada sem nó cabeça ordenada: busca, inserção e remoção;
// Lista duplamente encadeada com nó cabeça (sem ordenação): busca, inserção e remoção;
// Fila (FIFO): inserção e remoção;
// Pilha (LIFO): inserção e remoção.
// Após a realização de cada operação solicitada pelo usuário a estrutura de dados manipulada deve ser automaticamente impressa em tela.
// No encerramento do programa, toda a memória alocada dinamicamente deve ser desalocada.
// O código deve estar devidamente organizado, identado, comentado e sem erros ou avisos usando as opções -Wall -Wextra -pedantic do gcc.

// Estrutura de Pilha

typedef struct pilha {
    int value;
    struct pilha *topo;
} Pilha;

// Estrutura de Fila

typedef struct no
{
    int value;
    struct no *Inicio;
    struct no *Fim;
} Fila;

// Estrutura de uma Lista Simplesmente Encadeada

typedef struct no
{
    int value;
    struct no *prox;
} Simp;

// Estrutura de uma Lista Duplamente Encadeada

typedef struct no
{
    int value;
    struct no *prox;
} Dupl;

// Estrutura de uma Lista Simplesmente Encadeada Circular

typedef struct no
{
    int value;
    struct no *prox;
} SimpCirc;

// Inserção na Pilha
void inserePilha(Pilha **ptPiLha, int x)
{
    Pilha *new = malloc(sizeof(Pilha));
    new->value = x;
    new->topo = *ptPiLha;
    *ptPiLha = new;
    return;
}