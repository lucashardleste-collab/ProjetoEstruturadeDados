#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// Local para alterar e configurar o tamanho do vetor
#define TAMANHO 5000
#define LIMITE_MAX 1000

// Função geradora de numeros aleatorios
int meu_rand(int limite_max) {
	return rand() % limite_max;
}

// Função auxiliar para copiar o vetor
void copiarVetor(int *origem, int *destino, int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		destino[i] = origem[i];
	}
}

// Aqui para baixo são todas as funçõe se cada um tem um tipo de método de ordenação
void bubbleSort(int *vetor, int tamanho) {
	int i, j, temp;
	for (i = 0; i < tamanho - 1; i++) {
		for (j = 0; j < tamanho - i - 1; j++) {
			if (vetor[j] > vetor[j + 1]) {
				temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}
}


void insertionSort(int *vetor, int tamanho) {
	int i, j, chave;
	for (i = 1; i < tamanho; i++) {
		chave = vetor[i];
		j = i - 1;
		while (j >= 0 && vetor[j] > chave) {
			vetor[j + 1] = vetor[j];
			j = j - 1;
		}
		vetor[j + 1] = chave;
	}
}

void selectionSort(int *vetor, int tamanho) {
	int i, j, min_idx, temp;
	for (i = 0; i < tamanho - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < tamanho; j++) {
			if (vetor[j] < vetor[min_idx]) {
				min_idx = j;
			}
		}
		if (min_idx != i) {
			temp = vetor[min_idx];
			vetor[min_idx] = vetor[i];
			vetor[i] = temp;
		}
	}
}

void merge(int *vetor, int inicio, int meio, int fim) {
	int i, j, k;
	int n1 = meio - inicio + 1;
	int n2 = fim - meio;

	int *L = (int *)malloc(n1 * sizeof(int));
	int *R = (int *)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		L[i] = vetor[inicio + i];
	for (j = 0; j < n2; j++)
		R[j] = vetor[meio + 1 + j];

	i = 0;
	j = 0;
	k = inicio;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			vetor[k] = L[i];
			i++;
		} else {
			vetor[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		vetor[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		vetor[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);
}

void mergeSort(int *vetor, int inicio, int fim) {
	if (inicio < fim) {
		int meio = inicio + (fim - inicio) / 2;
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio + 1, fim);
		merge(vetor, inicio, meio, fim);
	}
}

int particionar(int *vetor, int baixo, int alto) {
	int pivo = vetor[alto];
	int i = (baixo - 1);
	int temp;
	for (int j = baixo; j <= alto - 1; j++) {
		if (vetor[j] < pivo) {
			i++;
			temp = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = temp;
		}
	}
	temp = vetor[i + 1];
	vetor[i + 1] = vetor[alto];
	vetor[alto] = temp;
	return (i + 1);
}

void quickSort(int *vetor, int baixo, int alto) {
	if (baixo < alto) {
		int pi = particionar(vetor, baixo, alto);
		quickSort(vetor, baixo, pi - 1);
		quickSort(vetor, pi + 1, alto);
	}
}


void heapify(int *vetor, int n, int i) {
	int maior = i;
	int esquerda = 2 * i + 1;
	int direita = 2 * i + 2;
	int temp;

	if (esquerda < n && vetor[esquerda] > vetor[maior])
		maior = esquerda;

	if (direita < n && vetor[direita] > vetor[maior])
		maior = direita;

	if (maior != i) {
		temp = vetor[i];
		vetor[i] = vetor[maior];
		vetor[maior] = temp;
		heapify(vetor, n, maior);
	}
}

void heapSort(int *vetor, int n) {
	int temp;
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(vetor, n, i);

	for (int i = n - 1; i > 0; i--) {
		temp = vetor[0];
		vetor[0] = vetor[i];
		vetor[i] = temp;
		heapify(vetor, i, 0);
	}
}


void countingSort(int *vetor, int tamanho) {
	if (tamanho <= 0) return;
	int max = vetor[0];
	for (int i = 1; i < tamanho; i++) {
		if (vetor[i] > max) max = vetor[i];
	}

	int *contador = (int *)calloc(max + 1, sizeof(int));
	if (!contador) return;

	for (int i = 0; i < tamanho; i++) {
		contador[vetor[i]]++;
	}

	int index = 0;
	for (int i = 0; i <= max; i++) {
		while (contador[i] > 0) {
			vetor[index++] = i;
			contador[i]--;
		}
	}
	free(contador);
}


void countingSortRadix(int *vetor, int tamanho, int exp) {
	int *saida = (int *)malloc(tamanho * sizeof(int));
	int contador[10] = {0};

	for (int i = 0; i < tamanho; i++)
		contador[(vetor[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		contador[i] += contador[i - 1];

	for (int i = tamanho - 1; i >= 0; i--) {
		saida[contador[(vetor[i] / exp) % 10] - 1] = vetor[i];
		contador[(vetor[i] / exp) % 10]--;
	}

	for (int i = 0; i < tamanho; i++)
		vetor[i] = saida[i];

	free(saida);
}

void radixSort(int *vetor, int tamanho) {
	if (tamanho <= 0) return;
	int max = vetor[0];
	for (int i = 1; i < tamanho; i++)
		if (vetor[i] > max)
			max = vetor[i];

	for (int exp = 1; max / exp > 0; exp *= 10)
		countingSortRadix(vetor, tamanho, exp);
}


typedef struct NoBucket {
	int dado;
	struct NoBucket* proximo;
} NoBucket;

void bucketSort(int *vetor, int tamanho) {
	if (tamanho <= 0) return;
	int numBuckets = 100;
	NoBucket **baldes = (NoBucket **)calloc(numBuckets, sizeof(NoBucket *));
	if (!baldes) return;

	int max = vetor[0];
	for (int i = 1; i < tamanho; i++)
		if (vetor[i] > max) max = vetor[i];
	
	float divisor = (max == 0) ? 1.0 : (max + 1.0);

	for (int i = 0; i < tamanho; i++) {
		int indiceBucket = (int)((vetor[i] * numBuckets) / divisor);
		if (indiceBucket >= numBuckets) indiceBucket = numBuckets - 1;

		NoBucket *novoNo = (NoBucket *)malloc(sizeof(NoBucket));
		novoNo->dado = vetor[i];
		novoNo->proximo = NULL;

		if (baldes[indiceBucket] == NULL || baldes[indiceBucket]->dado >= novoNo->dado) {
			novoNo->proximo = baldes[indiceBucket];
			baldes[indiceBucket] = novoNo;
		} else {
			NoBucket *atual = baldes[indiceBucket];
			while (atual->proximo != NULL && atual->proximo->dado < novoNo->dado) {
				atual = atual->proximo;
			}
			novoNo->proximo = atual->proximo;
			atual->proximo = novoNo;
		}
	}

	int index = 0;
	for (int i = 0; i < numBuckets; i++) {
		NoBucket *atual = baldes[i];
		while (atual != NULL) {
			vetor[index++] = atual->dado;
			NoBucket *temp = atual;
			atual = atual->proximo;
			free(temp);
		}
	}
	free(baldes);
}

// Codigo principal
int main() {
	srand((unsigned int)time(NULL));

	// Alocação de memoria para todos os vetores de teste
	int *vetor_original = (int *)malloc(TAMANHO * sizeof(int));
	int *v_bubble = (int *)malloc(TAMANHO * sizeof(int));
	int *v_insertion = (int *)malloc(TAMANHO * sizeof(int));
	int *v_selection = (int *)malloc(TAMANHO * sizeof(int));
	int *v_merge = (int *)malloc(TAMANHO * sizeof(int));
	int *v_quick = (int *)malloc(TAMANHO * sizeof(int));
	int *v_heap = (int *)malloc(TAMANHO * sizeof(int));
	int *v_counting = (int *)malloc(TAMANHO * sizeof(int));
	int *v_radix = (int *)malloc(TAMANHO * sizeof(int));
	int *v_bucket = (int *)malloc(TAMANHO * sizeof(int));

	if (!vetor_original || !v_bubble || !v_insertion || !v_selection || !v_merge || 
	    !v_quick || !v_heap || !v_counting || !v_radix || !v_bucket) {
		printf("Erro ao alocar mem�ria!\n");
		return 1;
	}

	// Preenche o vetor original
	for (int i = 0; i < TAMANHO; i++) {
		vetor_original[i] = meu_rand(LIMITE_MAX);
	}

	// Copia o contedo para todos os vetores de teste manterem exatamente os mesmos dados
	copiarVetor(vetor_original, v_bubble, TAMANHO);
	copiarVetor(vetor_original, v_insertion, TAMANHO);
	copiarVetor(vetor_original, v_selection, TAMANHO);
	copiarVetor(vetor_original, v_merge, TAMANHO);
	copiarVetor(vetor_original, v_quick, TAMANHO);
	copiarVetor(vetor_original, v_heap, TAMANHO);
	copiarVetor(vetor_original, v_counting, TAMANHO);
	copiarVetor(vetor_original, v_radix, TAMANHO);
	copiarVetor(vetor_original, v_bucket, TAMANHO);

	// --- TESTES DE TEMPO ---

	clock_t inicio, fim;

	inicio = clock(); bubbleSort(v_bubble, TAMANHO); fim = clock();
	double t_bubble = (double)(fim - inicio) / CLOCKS_PER_SEC;

	inicio = clock(); insertionSort(v_insertion, TAMANHO); fim = clock();
	double t_insertion = (double)(fim - inicio) / CLOCKS_PER_SEC;

	inicio = clock(); selectionSort(v_selection, TAMANHO); fim = clock();
	double t_selection = (double)(fim - inicio) / CLOCKS_PER_SEC;

	inicio = clock(); mergeSort(v_merge, 0, TAMANHO - 1); fim = clock();
	double t_merge = (double)(fim - inicio) / CLOCKS_PER_SEC;

	inicio = clock(); quickSort(v_quick, 0, TAMANHO - 1); fim = clock();
	double t_quick = (double)(fim - inicio) / CLOCKS_PER_SEC;

	inicio = clock(); heapSort(v_heap, TAMANHO); fim = clock();
	double t_heap = (double)(fim - inicio) / CLOCKS_PER_SEC;

	inicio = clock(); countingSort(v_counting, TAMANHO); fim = clock();
	double t_counting = (double)(fim - inicio) / CLOCKS_PER_SEC;

	inicio = clock(); radixSort(v_radix, TAMANHO); fim = clock();
	double t_radix = (double)(fim - inicio) / CLOCKS_PER_SEC;

	inicio = clock(); bucketSort(v_bucket, TAMANHO); fim = clock();
	double t_bucket = (double)(fim - inicio) / CLOCKS_PER_SEC;

	// --- IMPRESSAO DOS RESULTADOS ---
	printf("Resultados para TAMANHO = %d e LIMITE_MAX = %d:\n\n", TAMANHO, LIMITE_MAX);
	printf("Bubble Sort:    %.6f segundos\n", t_bubble);
	printf("Insertion Sort: %.6f segundos\n", t_insertion);
	printf("Selection Sort: %.6f segundos\n", t_selection);
	printf("Merge Sort:     %.6f segundos\n", t_merge);
	printf("Quick Sort:     %.6f segundos\n", t_quick);
	printf("Heap Sort:      %.6f segundos\n", t_heap);
	printf("Counting Sort:  %.6f segundos\n", t_counting);
	printf("Radix Sort:     %.6f segundos\n", t_radix);
	printf("Bucket Sort:    %.6f segundos\n", t_bucket);

	// Liberação de toda a memória alocada
	free(vetor_original);
	free(v_bubble);
	free(v_insertion);
	free(v_selection);
	free(v_merge);
	free(v_quick);
	free(v_heap);
	free(v_counting);
	free(v_radix);
	free(v_bucket);

	return 0;
}
