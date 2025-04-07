#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;       // Valor armazenado no nó
    struct no *prox; // Ponteiro para o próximo nó da lista
} No;

// ================== INSERÇÃO ==================

// Insere no início da lista
void Insere_Inicio(No **lista, int valor)
{
    No *novo = malloc(sizeof(No)); // Aloca memória para o novo nó
    novo->valor = valor;           // Atribui o valor ao novo nó
    novo->prox = *lista;           // Aponta para o antigo início da lista
    *lista = novo;                 // Atualiza o início da lista
}

// Insere no final da lista (iterativo)
void Insere_Fim_Itr(No **Lista, int dado)
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

// Insere no final da lista (recursivo)
void Insere_Fim_Rec(No **Lista, int dado)
{
    if (*Lista == NULL) // Caso base: fim da lista
    {
        *Lista = malloc(sizeof(No)); // Cria novo nó
        (*Lista)->prox = NULL;
        (*Lista)->valor = dado;
    }
    else
        Insere_Fim_Rec(&((*Lista)->prox), dado); // Chama recursivamente no próximo nó
}

// Insere em uma posição específica (recursivo)
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

// Função que insere ordenado recursivamente
void Insere_Ordenado_Rec(No **Lista, int val)
{

    if (*Lista == NULL || (*Lista)->valor > val)
    {
        No *novoNo = malloc(sizeof(No));
        novoNo->valor = val;
        novoNo->prox = *Lista;
        *Lista = novoNo;
        return;
    }

    Insere_Ordenado_Rec(&(*Lista)->prox, val);
}

// ================== REMOÇÃO ==================

// Remove um valor da lista (recursivo)
void Remove_Val_Rec(No **Lista, int val)
{
    if ((*Lista)->valor == val)
    {
        No *aux = *Lista;        // Guarda o nó que será removido
        *Lista = (*Lista)->prox; // Pula o nó da lista
        free(aux);               // Libera memória
    }
    else
    {
        Remove_Val_Rec(&(*Lista)->prox, val); // Chamada recursiva
    }
}
// Remove um intervalo de valores da lista encadeada
void Remove_Intervalo_Rec(No **Lista, int ini, int fim)
{
    if (*Lista == NULL || ini > fim)
    {
        return;
    }

    if (ini == 0)
    {
        No *aux = *Lista;        // Guarda o nó que será removido
        *Lista = (*Lista)->prox; // Pula o nó da lista
        free(aux);               // Libera memória
        Remove_Intervalo_Rec(&(*Lista), 0, fim - 1);
    }
    else
    {
        Remove_Intervalo_Rec(&(*Lista), ini - 1, fim - 1);
    }
}

// ================== BUSCA ==================

// Busca um valor na lista (recursivo)
void Buscar_Valor_Rec(No *Lista, int valor, int *resp)
{
    if (Lista == NULL) // Caso base: não encontrado
    {
        *resp = 0;
        return;
    }

    if (Lista->valor == valor) // Encontrado
    {
        *resp = 1;
        return;
    }

    // Chamada recursiva
    Buscar_Valor_Rec(Lista->prox, valor, resp);
}

// ================== UTILITÁRIOS ==================

// Imprime a lista
void Imprime(No *Lista)
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

// Calcula o tamanho da lista (recursivo)
void Tamanho_Lista_Rec(No *Lista, int *resp)
{
    if (Lista == NULL)
    {
        return;
    }
    (*resp)++;

    Tamanho_Lista_Rec(Lista->prox, resp);
}

// Compara duas listas para ver se são iguais

void Compara_Rec(No *Lista1, No *Lista2, int *res)
{
    if (Lista1 == NULL && Lista2 == NULL)
    {
        *res = 1;
        return;
    }

    if (Lista1 == NULL || Lista2 == NULL)
    {
        *res = 0;
        return;
    }

    if (Lista1->valor != Lista2->valor)
    {
        *res = 0;
        return;
    }

    Compara_Rec(Lista1->prox, Lista2->prox, res);
}

// ================== ORDENAÇÃO ==================

int main()
{

    No *Lista = NULL;
    Insere_Fim_Rec(&Lista, 0);
    Insere_Fim_Rec(&Lista, 1);
    Insere_Fim_Rec(&Lista, 2);
    Insere_Fim_Rec(&Lista, 3);
    Insere_Fim_Rec(&Lista, 4);
    // Insere_Fim_Rec(&Lista, 5);
    Insere_Fim_Rec(&Lista, 6);
    Insere_Fim_Rec(&Lista, 7);
    Insere_Fim_Rec(&Lista, 8);
    Insere_Fim_Rec(&Lista, 9);
    Insere_Fim_Rec(&Lista, 10);

    Imprime(Lista);

    Remove_Intervalo_Rec(&Lista, 0, 6);
    Imprime(Lista);
    Insere_Ordenado_Rec(&Lista, 5);
    Insere_Ordenado_Rec(&Lista, 15);
    Insere_Ordenado_Rec(&Lista, 100);
    Insere_Ordenado_Rec(&Lista, 75);
    Insere_Ordenado_Rec(&Lista, 150);
    Imprime(Lista);

    return 0;
}