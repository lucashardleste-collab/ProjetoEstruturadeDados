
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    int n, i;
    float total = 0.0;
    float *vetor = NULL;

    printf("Digite quantos termos voce deseja: \n");
    scanf("%i", &n);

    vetor = (float *) calloc(n,sizeof(float));

    if (vetor == NULL){
        printf("Erro na Alocacao");
        return 1;
    }

    for(i = 0; i < n; i++){
        printf("Digite o valor do %i termo: \n", i+1);
        scanf("%f", &vetor[i]);
        total = total + vetor[i];
    }

    printf("O Total da soma dos valores e: %f e a media e: %f", total, total/n);

    free(vetor);
    vetor = NULL;

}