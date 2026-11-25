#include <stdio.h>
#include <stdlib.h>

int conversor(int decimal){
	
    if(decimal < 2){
        return decimal;
    }

    return conversor(decimal / 2) *10 + decimal % 2;
}

int main() { 
	
    int decimal;

    printf("Digite o valor decimal: ");
    scanf("%d", &decimal);

    printf("O valor decimal %d em binario e: %d", decimal, conversor(decimal));

}
