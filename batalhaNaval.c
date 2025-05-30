#include <stdio.h>
#include <stdlib.h> // para abs()

#define tamtabuleiro 10   // Tamanho do tabuleiro
#define dimensaohab 5     // Dimensão das habilidades
#define agua 0            // Representação da água
#define habilidade 5      // Representação de uma habilidade

// Inicializa o tabuleiro com água
void tabuleiroinit(int tabuleiro[tamtabuleiro][tamtabuleiro]) {
    for (int i = 0; i < tamtabuleiro; i++) {
        for (int j = 0; j < tamtabuleiro; j++) {
            tabuleiro[i][j] = agua;
        }
    }
}

// Imprime o tabuleiro
void tabuimp(int tabuleiro[tamtabuleiro][tamtabuleiro]) {
    for (int i = 0; i < tamtabuleiro; i++) {
        for (int j = 0; j < tamtabuleiro; j++) {
            if (tabuleiro[i][j] == agua)
                printf("0 ");
            else if (tabuleiro[i][j] == habilidade)
                printf("5 ");
        }
        printf("\n");
    }
}

// Define a habilidade em forma de cone
void cone(int matriz[dimensaohab][dimensaohab]) {
    for (int i = 0; i < dimensaohab; i++) {
        for (int j = 0; j < dimensaohab; j++) {
            if (j >= dimensaohab / 2 - i && j <= dimensaohab / 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Define a habilidade em forma de cruz
void cruz(int matriz[dimensaohab][dimensaohab]) {
    for (int i = 0; i < dimensaohab; i++) {
        for (int j = 0; j < dimensaohab; j++) {
            if (i == dimensaohab / 2 || j == dimensaohab / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Define a habilidade em forma de losango
void losango(int matriz[dimensaohab][dimensaohab]) {
    for (int i = 0; i < dimensaohab; i++) {
        for (int j = 0; j < dimensaohab; j++) {
            if (abs(i - 1) + abs(j - 1) <= 1)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Aplica uma habilidade no tabuleiro
void aplicarhabilidade(int tabuleiro[tamtabuleiro][tamtabuleiro],
                       int habilidade1[dimensaohab][dimensaohab],
                       int origemi, int origemj) {
    for (int i = 0; i < dimensaohab; i++) {
        for (int j = 0; j < dimensaohab; j++) {
            int posi = origemi + i - dimensaohab / 2;
            int posj = origemj + j - dimensaohab / 2;

            if (posi >= 0 && posi < tamtabuleiro && posj >= 0 && posj < tamtabuleiro) {
                if (habilidade1[i][j] == 1 && tabuleiro[posi][posj] == agua) {
                    tabuleiro[posi][posj] = habilidade;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[tamtabuleiro][tamtabuleiro];
    int cone1[dimensaohab][dimensaohab];
    int cruz1[dimensaohab][dimensaohab];
    int losango1[dimensaohab][dimensaohab];

    tabuleiroinit(tabuleiro);
    cone(cone1);
    cruz(cruz1);
    losango(losango1);

    aplicarhabilidade(tabuleiro, cone1, 2, 2);
    aplicarhabilidade(tabuleiro, cruz1, 5, 7);
    aplicarhabilidade(tabuleiro, losango1, 8, 3);

    printf("Tabuleiro final com habilidades:\n");
    tabuimp(tabuleiro);

    return 0;
}
