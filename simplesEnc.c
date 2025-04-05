#include <stdio.h>
#include <stdlib.h>

// Estrutura da lista Enc
// Resolvi usar essa estrutura por ser mais simples
typedef struct noSimplesEnc
{
    int valor;
    struct noSimplesEnc *prox;

} SimplesEnc;

void Insere_Inicio(SimplesEnc **lista, int valor)
{
    SimplesEnc *novo = malloc(sizeof(SimplesEnc));
    novo->valor = valor;
    novo->prox = *lista;
    *lista = novo;
}

void insere_Fim_Itr(SimplesEnc **Lista, int dado)
{
    SimplesEnc *novoNo = malloc(sizeof(SimplesEnc));
    novoNo->valor = dado;
    novoNo->prox = NULL;

    if (*Lista == NULL)
    {
        *Lista = novoNo;
        return;
    }

    SimplesEnc *aux = *Lista;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = novoNo;
}

void insere_Fim_Rec(SimplesEnc **Lista, int dado)
{
    if (*Lista == NULL)
    {
        *Lista = malloc(sizeof(SimplesEnc));
        (*Lista)->prox = NULL;
        (*Lista)->valor = dado;
    }
    else
        insere_Fim_Rec(&((*Lista)->prox), dado);
}

void Insere_Posicao_Rec(SimplesEnc **lista, int valor, int posicao)
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

        SimplesEnc *novo = (SimplesEnc *)malloc(sizeof(SimplesEnc));
        novo->valor = valor;
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    Insere_Posicao(&(*lista)->prox, valor, posicao - 1);
}

void imprime(SimplesEnc *Lista)
{
    SimplesEnc *aux = Lista;
    while (aux != NULL)
    {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }
}

int main()
{
    SimplesEnc *Lista = NULL;
    insere_Fim_Rec(&Lista, 1);
    insere_Fim_Rec(&Lista, 2);
    insere_Fim_Rec(&Lista, 3);
    imprime(Lista);
    Insere_Posicao(&Lista, 15, 1);
    printf("\n");
    imprime(Lista);
}