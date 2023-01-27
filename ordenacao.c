#include "ordenacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getNome(char nome[])
{
    // substitua por seu nome
    strncpy(nome, "Bruno Aquiles de Lima e Marcelo Gyovani Pereira", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] = '\0'; // adicionada terminação manual para caso de overflow
}

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR()
{
    return 20221230;
}

int buscaSequencial(int vetor[], int tam, int valor, int *numC)
{
    if (tam == 0)
        return -1;

    if ((*numC)++, vetor[tam - 1] == valor)
        return tam - 1;

    return buscaSequencial(vetor, tam - 1, valor, numC);
}

int aux_busca_binaria(int vetor[], int a, int b, int valor, int *numC)
{
    if (a > b)
        return -1;

    int m = (b + a) / 2;
    if ((*numC)++, vetor[m] == valor)
        return m;
    if ((*numC)++, valor > vetor[m])
        return aux_busca_binaria(vetor, m + 1, b, valor, numC);
    return aux_busca_binaria(vetor, a, m-1, valor, numC);
}

int buscaBinaria(int vetor[], int tam, int valor, int *numComparacoes)
{
    return aux_busca_binaria(vetor, 0, tam, valor, numComparacoes);
}

void troca(int *a, int *b)
{
    int aux = *a;

    *a = *b;
    *b = aux;
}

/* Retorna a posição de inserção de um elemento x num vetor de inicio a e fim b */
int buscaBinariaInsercao(int x, int vetor[], int a, int b, int *numC)
{
    if (a > b)
        return b + 1;
    int meio = (a + b) / 2;
    // descarta o valor de (*numC)++ e avalia o valor de vetor[meio] > x
    if ((*numC)++, vetor[meio] > x)
        return buscaBinariaInsercao(x, vetor, a, meio - 1, numC);
    if ((*numC)++, vetor[meio] < x)
        return buscaBinariaInsercao(x, vetor, meio + 1, b, numC);

    return meio;
}

void insere(int vetor[], int a, int b, int *numC)
{
    int p = buscaBinariaInsercao(vetor[b], vetor, a, b, numC);
    for (int i = b; i > p; i--)
        troca(vetor + i, vetor + i - 1);
}

void auxInsertionSort(int vetor[], int a, int b, int *numC)
{
    if (a > b)
        return;
    auxInsertionSort(vetor, a, b - 1, numC);
    insere(vetor, a, b, numC);
}

int insertionSort(int vetor[], int tam)
{
    int numC = 0;

    auxInsertionSort(vetor, 0, tam - 1, &numC);
    return numC;
}

int aux_selection(int vetor[], int a, int b, int *comparacoes)
{
    int menor;
    int i, aux;

    if (a == b)
        return 1;

    menor = a;
    for (i = a + 1; i <= b; i++)
    {
        (*comparacoes)++;
        if (vetor[menor] > vetor[i])
            menor = i;
    }
    aux = vetor[menor];
    vetor[menor] = vetor[a];
    vetor[a] = aux;

    return aux_selection(vetor, a + 1, b, comparacoes);
}

int selectionSort(int vetor[], int tam)
{
    int comparacoes = 0;

    aux_selection(vetor, 0, tam - 1, &comparacoes);

    return comparacoes;
}

void intercala(int v[], int a, int m, int b, int *numC)
{
    int *vet_aux = malloc(sizeof(int) * (b - a + 1));
    int i = a;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= b)
    {
        if ((*numC)++, v[i] <= v[j])
            vet_aux[k++] = v[i++];
        else
            vet_aux[k++] = v[j++];
    }

    /*Termina de passar os elementos q sobraram em um dos lados.*/
    while (i <= m)
        vet_aux[k++] = v[i++];
    while (j <= b)
        vet_aux[k++] = v[j++];
    k = 0;

    for (i = a; i <= b; i++)
    {
        v[i] = vet_aux[k++];
    }

    free(vet_aux);
}

/*Vai fazer a recursão do mergeSort.*/
void aux_merge(int vet[], int a, int b, int *numC)
{
    if (a < b)
    {
        int m = a + (b - a) / 2;
        aux_merge(vet, a, m, numC);
        aux_merge(vet, m + 1, b, numC);
        intercala(vet, a, m, b, numC);
    }
}

int mergeSort(int vetor[], int tam)
{
    int numComparacoes = 0;

    aux_merge(vetor, 0, tam - 1, &numComparacoes);
    return numComparacoes;
}

int particiona(int vetor[], int a, int b, int x, int *numC)
{
    int meio = a - 1;
    for (int i = a; i <= b; i++)
        if ((*numC)++, vetor[i] <= x) {
            meio++;
            troca(vetor + meio, vetor + i);
        }

    return meio;
}

void auxQuickSort(int vetor[], int a, int b, int *numC)
{
    if (a >= b)
        return;
    int meio = particiona(vetor, a, b, vetor[b], numC);
    auxQuickSort(vetor, a, meio - 1, numC);
    auxQuickSort(vetor, meio + 1, b, numC);
}

int quickSort(int vetor[], int tam)
{
    int numC = 0;

    auxQuickSort(vetor, 0, tam - 1, &numC);
    return numC;
}

/* Retorna o indíce do filho esquerdo de um nodo de uma árvore binária */
int filhoE(int i)
{
    return 2 * i + 1;
}

/* Retorna o indíce do filho direito de um nodo de uma árvore binária */
int filhoD(int i)
{
    return 2 * i + 2;
}

void maxHeapify(int vetor[], int i, int tam, int *numC)
{
    int esq = filhoE(i);
    int dir = filhoD(i);
    int maior = i;

    if (esq < tam && ((*numC)++, vetor[esq] > vetor[i]))
            maior = esq;
    if (dir < tam && ((*numC)++, vetor[dir] > vetor[maior]))
            maior = dir;
    if (maior != i) {
        troca(vetor + i, vetor + maior);
        maxHeapify(vetor, maior, tam, numC);
    }
}

void buildMaxHeap(int vetor[], int tam, int *numC)
{
    for (int i = tam / 2; i >= 0; i--) 
        maxHeapify(vetor, i, tam, numC);
}

int heapSort(int vetor[], int tam)
{
    int numC = 0;

    buildMaxHeap(vetor, tam, &numC);
    for (int i = tam - 1; i > 0; i--) {
        troca(vetor, vetor + i);
        maxHeapify(vetor, 0, i, &numC);
    }
    return numC;
}
