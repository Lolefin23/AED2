#include <stdio.h>
#include <stdlib.h>

typedef struct noSimplesEnc
{
    int valor;
    struct noSimplesEnc *prox;

} SimplesEnc;

void insereFinalLaco(SimplesEnc **Lista, int dado)
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

void insereFinalRec(SimplesEnc **Lista, int dado)
{
    if (*Lista == NULL)
    {
        *Lista = malloc(sizeof(SimplesEnc));
        (*Lista)->prox = NULL;
        (*Lista)->valor = dado;
    }
    else
        insereFinalRec(&((*Lista)->prox), dado);
}

void Insere_Posicao(SimplesEnc **lista, int valor, int posicao)
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
    insereFinalRec(&Lista, 1);
    insereFinalRec(&Lista, 2);
    insereFinalRec(&Lista, 3);
    imprime(Lista);
    Insere_Posicao(&Lista, 15, 1);
    printf("\n");
    imprime(Lista);
}