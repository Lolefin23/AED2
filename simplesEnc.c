#include <stdio.h>
#include <stdlib.h>

// Estrutura da lista Enc
// Resolvi usar essa estrutura por ser mais simples
typedef struct no
{
    int valor;
    struct no *prox;

} No;

void Insere_Inicio(No **lista, int valor)
{
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *lista;
    *lista = novo;
}

void insere_Fim_Itr(No **Lista, int dado)
{
    No *novoNo = malloc(sizeof(No));
    novoNo->valor = dado;
    novoNo->prox = NULL;

    if (*Lista == NULL)
    {
        *Lista = novoNo;
        return;
    }

    No *aux = *Lista;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = novoNo;
}

void insere_Fim_Rec(No **Lista, int dado)
{
    if (*Lista == NULL)
    {
        *Lista = malloc(sizeof(No));
        (*Lista)->prox = NULL;
        (*Lista)->valor = dado;
    }
    else
        insere_Fim_Rec(&((*Lista)->prox), dado);
}

void Insere_Posicao_Rec(No **lista, int valor, int posicao)
{
    if (posicao < 0)
    {
        printf("Posição inválida.\n");
        return;
    }

    if (*lista == NULL && posicao > 0)
    {
        printf("Posição fora dos limites.\n");
        return;
    }

    if (posicao == 0)
    {

        No *novo = (No *)malloc(sizeof(No));
        novo->valor = valor;
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    Insere_Posicao_Rec(&(*lista)->prox, valor, posicao - 1);
}

void imprime(No *Lista)
{
    No *aux = Lista;
    while (aux->prox != NULL)
    {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
    printf("%d", aux->valor);
}

void buscar_Valor_Rec(No *Lista, int valor, int *resp)
{
    if (Lista == NULL)
    {
        *resp = 0;
        return;
    }
    if (Lista->valor == valor)
    {
        *resp = 1;
        return;
    }

    buscar_Valor_Rec(Lista->prox, valor, resp);
}

int main()
{
    No *Lista = NULL;
    insere_Fim_Rec(&Lista, 1);
    insere_Fim_Rec(&Lista, 2);
    insere_Fim_Rec(&Lista, 3);
    imprime(Lista);
    Insere_Posicao_Rec(&Lista, 15, 1);
    printf("\n");
    imprime(Lista);
    int resp;
    buscar_Valor_Rec(Lista, 115, &resp);

    printf("\n%d\n", resp);
}