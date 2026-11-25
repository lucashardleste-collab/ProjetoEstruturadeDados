#include <stdio.h>
#include <stdlib.h>

int rastreio(int vetor[], int inicio, int fim, int busca){
	
	if (vetor[inicio] == busca){
	
		return inicio;
	}

    if (inicio == fim && vetor[inicio] != busca){

        return -1;
    }

    return rastreio(vetor , inicio + 1, fim, busca);

}

int main() { 
	
    int vetor[6] = {3, 7, 12, 18, 25, 30};
    int inicio = 0;
    int fim;
    int busca;

    printf("Digite o valor de busca: ");
    scanf("%d", &busca);

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &fim);

    printf("O valor buscado %d esta na posicao: %d", busca, rastreio(vetor, inicio, fim - 1, busca));

}
