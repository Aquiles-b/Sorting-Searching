#include "ordenacao.h"
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

int mergeSort(int vetor[], int tam){
    vetor[0] = 99;
    return -1;
}

int quickSort(int vetor[], int tam){
    vetor[0] = 99;
    return -1;
}

int heapSort(int vetor[], int tam){
    vetor[0] = 99;
    return -1;
}
