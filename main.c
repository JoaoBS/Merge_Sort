#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int vetor[], int ini, int meio, int fim) {
	
	int i, j, k;
	int aux1 = meio - ini + 1;
	int aux2 = fim - meio;

	int vet1[aux1];
	int vet2[aux2];

	for (i = 0; i < aux1; i++) {
		vet1[i] = vetor[ini + i];	
	}
		
	for (j = 0; j < aux2; j++) {
		vet2[j] = vetor[meio + 1 + j];
	}
		
	i = 0;
	j = 0;
	k = ini; 
	while (i < aux1 && j < aux2) {
		if (vet1[i] <= vet2[j]) {
			vetor[k] = vet1[i];
			i++;
		}
		else {
			vetor[k] = vet2[j];
			j++;
		}
		k++;
	}

	while (i < aux1) {
		vetor[k] = vet1[i];
		i++;
		k++;
	}

	while (j < aux2) {
		vetor[k] = vet2[j];
		j++;
		k++;
	}
}

void mergeSort(int vetor[], int ini, int fim) {
	if (ini < fim) {
	
		int meio = (ini + fim) / 2;
		
		mergeSort(vetor, ini, meio);
	
		mergeSort(vetor, meio + 1, fim);

		merge(vetor, ini, meio, fim);
	}
}

int main(int argc, char *argv[]) {
	
	int vetor[1000];
	int i;
	FILE *arquivo;
	int tam = sizeof(vetor) / sizeof(int);
	
	arquivo = fopen("Merge Sort.txt", "w");
	
	srand(time(NULL));
	
	printf("Desordenado:\n");
	fprintf(arquivo, "Desordenado:\n");
	
	for(i = 0; i < tam; i++) {
		vetor[i] = rand() % 1000;
		printf("%d ", vetor[i]);
		fprintf(arquivo, "%d ", vetor[i]);
	}
	
	printf("\n\n");
	fprintf(arquivo, "\n\n");
	
	mergeSort(vetor, 0, tam - 1);

	printf("Ordenado:\n");
	fprintf(arquivo, "Ordenado:\n");
	
	for(i = 0; i < tam; i++) {
		printf("%d ", vetor[i]);
		fprintf(arquivo, "%d ", vetor[i]);
	}
	
	fclose(arquivo);
	
	return 0;
}
