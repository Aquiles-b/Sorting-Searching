#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define SHUFFLE_SWAP_NUM 100000

int aleat(int min, int max) {
    return min + (rand() % (max - min + 1));
}

void shuffle(int *vet, int tam) {
    int a, b, aux;
    for (int i = 0; i < SHUFFLE_SWAP_NUM; i++) {
        a = aleat(0, tam - 1);
        b = aleat(0, tam - 1);
        aux = vet[a];
        vet[a] = vet[b];
        vet[b] = aux;
    }
}

void printSeparador() {
    printf("----------------------------------\n");
}

void imprime_vet(int *vet, int tam){
    for(int i=0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf ("\n");
}

int verificaOrdem(int vetor[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        if (vetor[i] > vetor[i + 1])
            return 0;
    }
    return 1;
}

void estaOrdenado(int vetor[], int tam) {
    if (verificaOrdem(vetor, tam))
        printf("    O vetor esta ordenado\n");
    else
        printf("    O vetor nao esta ordenado\n");
}

// Transforma o vetor em um vetor [tam - 1..0]
void vetorDecrescente(int vetor[], int tam) {
    for (int i = tam - 1, j = 0; i >= 0; i--){
        vetor[i] = j;
        j++;
    }
}

void imprimeTeste(int vetor[], int tam, int sortfunc(int*, int)) {
    clock_t start, end;//variáveis do tipo clock_t
    double total;
    int numComp;

    start = clock();
    numComp = sortfunc(vetor, tam);
    end = clock();
    printf("    Custo de comparações: %d\n", numComp);
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("    Tempo total: %f\n", total);
    estaOrdenado(vetor, tam);
}

void testaSort(int vetor[], int tam, int sortfunc(int*, int)) {
    /* Testa com vetor embaralhado */
    printf("- Vetor embaralhado\n");
    shuffle(vetor, tam);
    imprimeTeste(vetor, tam, sortfunc);
    printf("\n");

    /* Testa com vetor ordenado ao contrário */
    printf("- Vetor ordenado ao contrário\n");
    vetorDecrescente(vetor, tam);
    imprimeTeste(vetor, tam, sortfunc);
    printf("\n");

    /* Testa com vetor ordenado */
    printf("- Vetor ordenado\n");
    imprimeTeste(vetor, tam, sortfunc);

    printSeparador();
}

void testaBusca(int vetor[], int tam, int searchfunc(int*, int, int, int*), int num) {
    clock_t start, end;//variáveis do tipo clock_t
    double total;
    int numComp;
    int idxBusca;

    numComp = 0;
    start = clock();//start recebe o "ciclo" corrente
    idxBusca = searchfunc(vetor, tam, num, &numComp);
    end = clock();//end recebe o "ciclo" corrente
    printf("    Indice: %d Custo: %d\n", idxBusca, numComp);
    //o tempo total é a diferença dividia pelos ciclos por segundo
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("    Tempo total: %f\n\n", total);

    printSeparador();
}

int main(){
    char nome[MAX_CHAR_NOME];
    int j = 0;
    int i;

    int num = 31415;/*Numero para ser procurado no vetor pelas buscas.*/

    //Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
    //Veja um exemplo de alocação dinâmica a seguir
    int tamVetor = 50000;
    int* vetor = malloc(tamVetor * sizeof(int));
    if(vetor == NULL){
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());
    printf("GRR 20221225\n\n");

    srand(time(NULL));
    
    printSeparador();
    /*Merge Sort*/
    goto lixo;
    printf("Merge Sort\n");
    testaSort(vetor, tamVetor, mergeSort);
    
    /*Selection sort.*/
    printf("Selection Sort\n");
    testaSort(vetor, tamVetor, selectionSort);
    
    /*Insertion Sort*/
    lixo:
    printf("Insertion Sort\n");
    testaSort(vetor, tamVetor, insertionSortSequencial);

    /*Quick Sort*/
    printf("Quick Sort\n");
    testaSort(vetor, tamVetor, quickSort);

    /*Heap Sort*/
    printf("Heap Sort\n");
    testaSort(vetor, tamVetor, heapSort);
    
    /*Busca sequencial*/
    printf("Busca Sequencial\n");
    testaBusca(vetor, tamVetor, buscaSequencial, num);

    /*Busca binaria */
    printf("Busca Binaria\n");
    testaBusca(vetor, tamVetor, buscaBinaria, num);
    
    //É obrigatório que você libere a memória alocada dinamicamente via free
    free(vetor);

    return 0;
}
