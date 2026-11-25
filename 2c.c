
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    int linhas, colunas, i, j;
    int **matriz = NULL;

    printf("Digite quantas linhas voce deseja: \n");
    scanf("%i", &linhas);

    printf("Digite quantas colunas voce deseja: \n");
    scanf("%i", &colunas);


    matriz = (int **) calloc(linhas,sizeof(int));

    if (matriz == NULL){
        printf("Erro na Alocacao");
        return 1;
    }

    for(i = 0; i < linhas; i++){
        matriz[i] = (int *) calloc(colunas, sizeof(int));
    }

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("Digite o termo da linha %i coluna %i: \n", i+1, j+1);
            scanf("%i", &matriz[i][j]);
        }
    }

    printf("A matriz final ficou: \n");

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf(" %i ", matriz[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < linhas; i++){
        free(matriz[i]);
        matriz[i] = NULL;
    }

    free(matriz);
    matriz = NULL;

}