#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int num;
    struct no *prox;
} Lista;

void Remove_Val_Rec(Lista **ronaldo, int val)
{
    if ((*ronaldo)->num == val)
    {
        Lista *aux = *ronaldo;       // Guarda o nó que será removido
        *ronaldo = (*ronaldo)->prox; // Pula o nó da lista
        free(aux);                   // Libera memória
    }
    else
    {
        Remove_Val_Rec(&(*ronaldo)->prox, val); // Chamada recursiva
    }
}

void insereDuplicata(Lista **point, int x)
{
    Lista *aux = *point;
    Lista *novoNo = malloc(sizeof(Lista));

    novoNo->prox = NULL;
    novoNo->num = x;

    if (*point == NULL)
    {
        return;
    }

    if (aux->num == x)
    {
        novoNo->prox = aux;
        *point = novoNo;
        return;
    }

    while (aux->prox != NULL)
    {
        if (aux->prox->num == x)
        {
            novoNo->prox = aux->prox;
            aux->prox = novoNo;
            return;
        }
        aux = aux->prox;
    }
    return;
}

void deixaDupl(Lista **point)
{
    if ((*point) == NULL)
    {
        return;
    }
    Lista *p = *point;
    Lista *ant = NULL;

    while (p != NULL)
    {
        int cont = 0;
        Lista *aux = *point;

        while (aux != NULL)
        {
            if (aux->num == p->num)
            {
                cont++;
            }
            aux = aux->prox;
        }
        if (cont == 1)
        {
            Lista *temp = p;
            if (ant == NULL)
            {
                (*point)->prox;
            }
        }
    }
}

void Insere_Fim_Rec(Lista **Lista, int dado)
{
    if (*Lista == NULL) // Caso base: fim da lista
    {
        *Lista = malloc(sizeof(Lista)); // Cria novo nó
        (*Lista)->prox = NULL;
        (*Lista)->num = dado;
    }
    else
        Insere_Fim_Rec(&((*Lista)->prox), dado); // Chama recursivamente no próximo nó
}

void imprime(Lista *point)
{
    while (point != NULL)
    {
        printf("%d", point->num);
        if (point->prox != NULL)
            printf(" -> ");
        point = point->prox;
    }
    printf("\n");
}

Lista *Intercala(Lista *A, Lista *B)
{

    if (A == NULL)
        return B;
    if (B == NULL)
        return A;

    Lista *D = NULL;
    int cont = 0;
    while (A != NULL || B != NULL)
    {
        cont++;
        if (A != NULL && cont % 2 != 0)
        {
            Insere_Fim_Rec(&D, A->num);
            A = A->prox;
        }
        else if (B != NULL)

        {
            Insere_Fim_Rec(&D, B->num);
            B = B->prox;
        }
    }
    return D;
}
int Quantidade(int *V, int n, int x)
{
    if (n == 0)
    {
        return 0;
    }

    int cont = (V[n - 1] == x) ? 1 : 0;

    return cont + Quantidade(V, n - 1, x);
}

void intercalaProx(Lista **ListaA, Lista *ListaB)
{
    Lista *Aprox, *Bprox;
    Lista *Agora = *ListaA;
    Lista *Bgora = ListaB;

    if (*ListaA == NULL)
    {
        *ListaA = ListaB;
        return;
    }
    if (ListaB == NULL)
    {
        return;
    }

    while (Agora != NULL && Bgora != NULL)
    {
        Aprox = Agora->prox;
        Bprox = Bgora->prox;

        Agora->prox = Bgora;
        Bgora->prox = Aprox;

        Agora = Aprox;
        Bgora = Bprox;
    }
}

int main()
{
    int vetor[5] = {2, 2, 3, 4, 5};
    Lista *pericles = NULL;
    Lista *ronaldo = NULL;
    Lista *D = NULL;
    Insere_Fim_Rec(&pericles, 1);
    Insere_Fim_Rec(&pericles, 3);
    Insere_Fim_Rec(&pericles, 5);
    Insere_Fim_Rec(&pericles, 7);
    Insere_Fim_Rec(&pericles, 9);
    Insere_Fim_Rec(&ronaldo, 2);
    Insere_Fim_Rec(&ronaldo, 4);
    Insere_Fim_Rec(&ronaldo, 6);
    Insere_Fim_Rec(&ronaldo, 8);
    Insere_Fim_Rec(&ronaldo, 10);
    imprime(pericles);
    imprime(ronaldo);
    D = Intercala(pericles, ronaldo);
    imprime(D);
    printf("\n%d\n", Quantidade(vetor, 5, 2));

    insereDuplicata(&pericles, 9);
    insereDuplicata(&pericles, 10);
    imprime(pericles);

    return 0;
}
