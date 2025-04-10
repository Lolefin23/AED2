#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;       // Valor armazenado no nó
    struct no *prox; // Ponteiro para o próximo nó da lista
    struct no *ant;  // Ponteiro para o nó anterior da lista
} No;

void Insere_Comeco(No **Lista, int valor)
{
    if (*Lista == NULL)
    {
        No *novoNo = malloc(sizeof(No));
        novoNo->prox = NULL;
        novoNo->ant = NULL;
        novoNo->valor = valor;
        *Lista = novoNo;
        return;
    }
    No *novoNo = malloc(sizeof(No));
    novoNo->prox = *Lista;
    novoNo->ant = NULL;
    novoNo->valor = valor;
    (*Lista)->ant = novoNo;
    return;
}

void imprime(No *Lista)
{
    No *aux = Lista;
    while (aux != NULL)
    {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
}

int main()
{
    No *Lista = NULL;
    Insere_Comeco(&Lista, 10);
    Insere_Comeco(&Lista, 9);
    Insere_Comeco(&Lista, 8);
    Insere_Comeco(&Lista, 7);
    Insere_Comeco(&Lista, 6);
    Insere_Comeco(&Lista, 5);
    Insere_Comeco(&Lista, 4);
    Insere_Comeco(&Lista, 3);
    Insere_Comeco(&Lista, 2);
    Insere_Comeco(&Lista, 1);

    imprime(Lista);
}
