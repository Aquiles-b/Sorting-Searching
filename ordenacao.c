#include "ordenacao.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getNome(char nome[]){
    //substitua por seu nome
    strncpy(nome, "Bruno Aquiles de Lima e Marcelo Gyovani Pereira", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR(){
    return 20221230;
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
    if (tam == 0)
        return -1;

    if (vetor[tam-1] == valor){
        (*numComparacoes)++;
        return tam-1;
    }
    (*numComparacoes)++;

    return buscaSequencial(vetor, tam-1, valor, numComparacoes);
}

int aux_busca_binaria(int vetor[], int a, int b, int valor, int *numComparacoes){
    if (a >= b)
        return -1;

    int m = (b + a)/2;
    if (vetor[m] == valor){
        (*numComparacoes)++;
        return m;
    }
    if (valor > vetor[m] ){
        (*numComparacoes) += 2;
        return aux_busca_binaria(vetor, m+1, b, valor, numComparacoes);
    }

    (*numComparacoes) += 2;
    return aux_busca_binaria(vetor, a, m, valor, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes){

    return aux_busca_binaria(vetor, 0, tam, valor, numComparacoes);
}

int insertionSort(int vetor[], int tam){	
    vetor[0] = 99;
    return -1;
}

int aux_selection(int vetor[], int a, int b, int *comparacoes){
    int menor;
    int i, aux;

    if (a == b)
        return 1;

    menor = a;
    for (i = a+1; i <= b; i++){
        (*comparacoes)++;
        if (vetor[menor] > vetor[i])
            menor = i;
    }
    aux = vetor[menor];
    vetor[menor] = vetor[a];
    vetor[a] = aux;

    return aux_selection(vetor, a+1, b, comparacoes);
}

int selectionSort(int vetor[], int tam){
    int comparacoes = 0;

    aux_selection(vetor, 0, tam-1, &comparacoes);

    return comparacoes;
}

void intercala(int v[], int a, int m, int b, int *numC){
    int *vet_aux = malloc(sizeof(int)*(b-a+1));
    int i = a;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= b){
        if (v[i] <= v[j])
            vet_aux[k++] = v[i++];
        else
            vet_aux[k++] = v[j++];
        (*numC)++;
    }

    /*Termina de passar os elementos q sobraram em um dos lados.*/
    while (i <= m)
        vet_aux[k++] = v[i++];
    while (j <= b)
        vet_aux[k++] = v[j++];
    k = 0;

    for (i = a; i <= b; i++){
        v[i] = vet_aux[k++];
    }

    free(vet_aux);
}

/*Vai fazer a recursão do mergeSort.*/
void aux_merge(int vet[], int a, int b, int *numC){
    if (a < b){
        int m = a+(b-a)/ 2;
        aux_merge(vet, a, m, numC);
        aux_merge(vet, m+1, b, numC);
        intercala(vet, a, m, b, numC);
    }
}

int mergeSort(int vetor[], int tam){
    int numComparacoes = 0;

    aux_merge(vetor, 0, tam-1, &numComparacoes);
    return numComparacoes;
}
/* teste */
int quickSort(int vetor[], int tam){
    vetor[0] = 99;
    return -1;
}

int heapSort(int vetor[], int tam){
    vetor[0] = 99;
    return -1;
}
