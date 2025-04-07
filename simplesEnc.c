#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;       // Valor armazenado no nó
    struct no *prox; // Ponteiro para o próximo nó da lista
} No;

// Insere um novo nó no início da lista
void Insere_Inicio(No **lista, int valor)
{
    No *novo = malloc(sizeof(No)); // Aloca memória para o novo nó
    novo->valor = valor;           // Atribui o valor ao novo nó
    novo->prox = *lista;           // Aponta para o antigo início da lista
    *lista = novo;                 // Atualiza o início da lista
}

// Insere um novo nó no final da lista de forma iterativa
void insere_Fim_Itr(No **Lista, int dado)
{
    No *novoNo = malloc(sizeof(No)); // Cria o novo nó
    novoNo->valor = dado;
    novoNo->prox = NULL; // O próximo é NULL (fim da lista)

    if (*Lista == NULL) // Se a lista estiver vazia
    {
        *Lista = novoNo; // O novo nó é o primeiro da lista
        return;
    }

    No *aux = *Lista;

    // Percorre a lista até o último nó
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    aux->prox = novoNo; // Liga o último nó ao novo nó
}

// Insere um novo nó no final da lista de forma recursiva
void insere_Fim_Rec(No **Lista, int dado)
{
    if (*Lista == NULL) // Caso base: fim da lista
    {
        *Lista = malloc(sizeof(No)); // Cria novo nó
        (*Lista)->prox = NULL;
        (*Lista)->valor = dado;
    }
    else
        insere_Fim_Rec(&((*Lista)->prox), dado); // Chama recursivamente no próximo nó
}

// Insere um novo nó em uma posição específica da lista (recursivamente)
void Insere_Posicao_Rec(No **lista, int valor, int posicao)
{
    if (posicao < 0) // Verifica se a posição é inválida
    {
        printf("Posição inválida.\n");
        return;
    }

    if (*lista == NULL && posicao > 0) // Verifica se chegou ao fim da lista antes da posição
    {
        printf("Posição fora dos limites.\n");
        return;
    }

    if (posicao == 0) // Caso base: posição correta encontrada
    {
        No *novo = (No *)malloc(sizeof(No)); // Cria o novo nó
        novo->valor = valor;
        novo->prox = *lista; // Liga o novo nó ao restante da lista
        *lista = novo;       // Atualiza o ponteiro atual
        return;
    }

    // Chamada recursiva com a próxima posição
    Insere_Posicao_Rec(&(*lista)->prox, valor, posicao - 1);
}

// Imprime todos os elementos da lista encadeada
void imprime(No *Lista)
{
    No *aux = Lista;

    // Enquanto não for o último nó
    while (aux->prox != NULL)
    {
        printf("%d -> ", aux->valor); // Imprime valor seguido de seta
        aux = aux->prox;
    }

    // Imprime o último valor (sem seta depois)
    printf("%d\n", aux->valor);
}

// Busca recursivamente um valor na lista e armazena o resultado em *resp
void buscar_Valor_Rec(No *Lista, int valor, int *resp)
{
    if (Lista == NULL) // Caso base: fim da lista sem encontrar
    {
        *resp = 0;
        return;
    }

    if (Lista->valor == valor) // Valor encontrado
    {
        *resp = 1;
        return;
    }

    // Chamada recursiva no próximo nó
    buscar_Valor_Rec(Lista->prox, valor, resp);
}

// Remove um valor nó com valor valo
void Remove_Val_Rec(No **Lista, int val)
{
    if ((*Lista)->valor == val)
    {
        No *aux = *Lista; // Criamos um nó auxiliar para guardar o endereço do que queremos remover
        *Lista = (*Lista)->prox; // Tiramos o que queremos remover da lista 
        free(aux); // Deleta o que queremos 
    }
    else
    {
        Remove_Val_Rec(&(*Lista)->prox, val);
    }
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
    Remove_Val_Rec(&Lista, 15);
    printf("\n");
    imprime(Lista);
}