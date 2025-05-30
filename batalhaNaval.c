#include <stdio.h>

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10] = {0};

    // Inicializações
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;
    tabuleiro[1][4] = 3;
    tabuleiro[3][3] = 3;
    tabuleiro[4][3] = 3;
    tabuleiro[5][3] = 3;
	tabuleiro[6][3] = 3;
	tabuleiro[0][0] = 3;
	tabuleiro[1][1] = 3;
	tabuleiro[2][2] = 3;
	tabuleiro[0][9] = 3;
	tabuleiro[1][8] = 3;
	tabuleiro[2][7] = 3;
    for (int i = 0; i < 10; i++) {
        tabuleiro[i][0];
    }

    // Imprimir cabeçalho das colunas - deu trabalho  - infelizmente tive que ir em buscar de ajuda do youtube pq nao ficou
    // muito bem entendido esa questao de como faço pra imprimir essas letrar na linha!
    
    
    for (int j = 0; j < 10; j++) {
        printf(" %c", linha[j]);
    }
    printf("\n");

    // Imprimir tabuleiro
    for (int i = 0; i < 10; i++) {
        printf("%2d", i + 1); // Número da linha
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }


		

    return 0;
}
