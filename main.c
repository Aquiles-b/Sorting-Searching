#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

void imprime_vet(int *vet, int tam){
    for(int i=0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf ("\n");
}

int main(){
    char nome[MAX_CHAR_NOME];
    int idxBusca;
    int numComp;

    //Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
    //Veja um exemplo de alocação dinâmica a seguir
    int tamVetor = 10;
    int* vetor = malloc(tamVetor * sizeof(int));
    if(vetor == NULL){
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }
    //Depois de alocado, o vetor pode ser utilizado normalmente
    //Não esqueça de desalocar no final do programa via free

    /*Vetor que o professor passou tem tamanho 3
    * com os elemento 1, 10 e 12 nessa ordem.*/
    vetor[0] = 21;
    vetor[1] = 0;
    vetor[2] = 12;
    vetor[3] = 3;
    vetor[4] = 1;
    vetor[5] = 5;
    vetor[6] = 6;
    vetor[7] = 4;
    vetor[8] = 22;
    vetor[9] = 8;

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());
    printf("GRR 20221225\n");

    //Para medir o tempo, inclua time.h, e siga o exemplo:
    clock_t start, end;//variáveis do tipo clock_t
    double total;

    imprime_vet(vetor, tamVetor);

    start = clock();
    numComp = mergeSort(vetor, 10);
    end = clock();
    printf("Merge Sort Custo: %d\n", numComp);
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo total: %f\n", total);

    imprime_vet(vetor, tamVetor);


    /*Selection sort.*/
    start = clock();
    numComp = selectionSort(vetor, 10);
    end = clock();
    printf("Selection Sort Custo: %d\n", numComp);
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo total: %f\n", total);

    imprime_vet(vetor, tamVetor);

    /* Tem que implementar esses ainda. */

    /* numComp = insertionSort(vetor, 3); */
    /* numComp = quickSort(vetor, 3); */
    /* numComp = heapSort(vetor, 3); */

    /*Busca sequencial*/
    numComp = 0;
    start = clock();//start recebe o "ciclo" corrente
    idxBusca = buscaSequencial(vetor, 10, 10, &numComp);
    end = clock();//end recebe o "ciclo" corrente
    printf("Busca sequencial indice: %d Custo: %d\n", idxBusca, numComp);
    //o tempo total é a diferença dividia pelos ciclos por segundo
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo total: %f\n", total);

    /*Busca binaria */
    numComp = 0;
    start = clock();
    idxBusca = buscaBinaria(vetor, 10, 12, &numComp);
    end = clock();
    printf("Busca binaria indice: %d Custo: %d\n", idxBusca, numComp);
    total = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Tempo total: %f\n", total);

    //É obrigatório que você libere a memória alocada dinamicamente via free
    free(vetor);

    return 0;
}
