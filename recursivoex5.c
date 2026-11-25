#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int labirinto(char matriz[5][5], int linhas, int colunas){

    if ( linhas < 0 || linhas >= 5 || colunas < 0 || colunas >= 5){
        return 0;
    }

    if ( matriz[linhas][colunas] == '1' || matriz[linhas][colunas] == 'X'){
        return 0;
    }

    if ( matriz[linhas][colunas] == 'F'){
        return 1;
    }

    matriz[linhas][colunas] = 'X';

    if (labirinto(matriz, linhas - 1, colunas)){
        return 1;
    }

    if (labirinto(matriz, linhas + 1, colunas)){
        return 1;
    }

    if (labirinto(matriz, linhas , colunas - 1)){
        return 1;
    }

    if (labirinto(matriz, linhas , colunas + 1)){
        return 1;
    }

    return 0;

}



int main (){

    int linhas = 0, colunas = 0, i, j;
    char matriz[5][5];

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("Digite o termo da linha %i coluna %i: \n", i+1, j+1);
            scanf(" %c", &matriz[i][j]);
        }
    }

    printf("A matriz final ficou: \n");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf(" %c ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("O Robo terminou o percurso? (-1 Nao / 0 Sim): %i", labirinto(matriz, linhas, colunas));

}