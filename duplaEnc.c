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
    (*Lista) = novoNo;
    return;
}

void Remove_Fim_Rec(No **Lista)
{
    if (*Lista == NULL)
    {
        return;
    }

    if ((*Lista)->prox == NULL)
    {
        free(*Lista);
        *Lista = NULL;
        return;
    }
    if ((*Lista)->prox != NULL && (*Lista)->prox->prox == NULL)
    {
        if ((*Lista)->prox->prox == NULL)
        {
            No *temp = (*Lista)->prox;
            (*Lista)->prox = NULL;
            free(temp);
            return;
        }
    }
    Remove_Fim_Rec(&(*Lista)->prox);
}

void Remove_Valor_Rec(No **Lista, int valor)
{
    // se a função for nula ela retorna
    if (*Lista == NULL)
    {
        return;
    }
    // se for o começo da lista

       if ((*Lista)->valor == valor && (*Lista)->ant == NULL)
    {

        if ((*Lista)->prox == NULL)
        {
            free(*Lista);
            *Lista = NULL;
            return;
        }
         No *temp = *Lista;
        (*Lista)->prox->ant = NULL;
        *Lista = (*Lista)->prox;
        free(temp);
        Remove_Valor_Rec(&(*Lista), valor);
        return;
    }

    if ((*Lista)->valor == valor && (*Lista)->ant != NULL && (*Lista)->prox != NULL)
    {
        No *temp = *Lista;
        (*Lista)->prox->ant = (*Lista)->ant;
        (*Lista)->ant->prox = (*Lista)->prox;
        free((temp));
    }

    if ((*Lista)->valor == valor && (*Lista)->prox == NULL)
    {
        No *temp = *Lista;
        (*Lista)->ant->prox = NULL;
        *Lista = (*Lista)->ant;
        free(temp);
        Remove_Valor_Rec(&(*Lista)->prox, valor);
        return;
    }

    Remove_Valor_Rec(&(*Lista)->prox, valor);
}

void imprime(No *Lista)
{
    if (Lista == NULL)
    {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", Lista->valor);
    imprime(Lista->prox);
}

int main()
{
    No *Lista = NULL;

    Insere_Comeco(&Lista, 4);
    Insere_Comeco(&Lista, 3);
    Insere_Comeco(&Lista, 2);
    Insere_Comeco(&Lista, 1);

    Remove_Valor_Rec(&Lista, 4);
    imprime(Lista);
    Remove_Valor_Rec(&Lista, 2);
    imprime(Lista);
    Remove_Valor_Rec(&Lista, 1);
    imprime(Lista);
}
