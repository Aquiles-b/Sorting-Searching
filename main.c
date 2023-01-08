#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main(){
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int numComp;

	//Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
	//Veja um exemplo de alocação dinâmica a seguir
	int tamVetor = 3;
	int* vetor = malloc(tamVetor * sizeof(int));
	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	//Depois de alocado, o vetor pode ser utilizado normalmente
	//Não esqueça de desalocar no final do programa via free
		
	vetor[0] = 1;
	vetor[1] = 10;
	vetor[2] = 12;

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	printf("GRR 20221225\n");

	//Para medir o tempo, inclua time.h, e siga o exemplo:
	clock_t start, end;//variáveis do tipo clock_t
    double total;

    numComp = 0;
	start = clock();//start recebe o "ciclo" corrente
	idxBusca = buscaSequencial(vetor, 3, 10, &numComp);
	end = clock();//end recebe o "ciclo" corrente
	printf("Busca sequencial %d %d\n", idxBusca, numComp);
	//o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);
    
    numComp = 0;
	start = clock();
	idxBusca = buscaBinaria(vetor, 3, 12, &numComp);
	end = clock();
	printf("Busca binaria %d %d\n", idxBusca, numComp);
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f\n", total);


	/* numComp = insertionSort(vetor, 3); */
	/* numComp = selectionSort(vetor, 3); */
	/* numComp = mergeSort(vetor, 3); */
	/* numComp = quickSort(vetor, 3); */
	/* numComp = heapSort(vetor, 3); */

	for(int i=0; i < 3; i++){
		printf("%d ", vetor[i]);
	}

    printf("\n");

	//É obrigatório que você libere a memória alocada dinamicamente via free
	free(vetor);

	return 0;
}
