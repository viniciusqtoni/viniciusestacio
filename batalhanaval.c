#include <stdio.h>
#include <stdlib.h>

#define TAB 10
#define HAB 5

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tab[TAB][TAB]) {
    for (int i = 0; i < TAB; i++) {
        for (int j = 0; j < TAB; j++) {
            tab[i][j] = 0;
        }
    }
}

// Posiciona alguns navios fixos (3)
void posicionarNavios(int tab[TAB][TAB]) {
    tab[2][2] = 3;
    tab[2][3] = 3;
    tab[4][7] = 3;
    tab[7][1] = 3;
}

// Cria habilidade em formato de CONE
void criarCone(int cone[HAB][HAB]) {
    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Cria habilidade em formato de CRUZ
void criarCruz(int cruz[HAB][HAB]) {
    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Cria habilidade em formato de OCTAEDRO (losango)
void criarOctaedro(int oct[HAB][HAB]) {
    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                oct[i][j] = 1;
            } else {
                oct[i][j] = 0;
            }
        }
    }
}

// Aplica a habilidade no tabuleiro
void aplicarHabilidade(int tab[TAB][TAB], int hab[HAB][HAB], int linha, int coluna) {
    int centro = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (hab[i][j] == 1) {
                int l = linha + i - centro;
                int c = coluna + j - centro;

                if (l >= 0 && l < TAB && c >= 0 && c < TAB) {
                    if (tab[l][c] == 0) {
                        tab[l][c] = 5;
                    }
                }
            }
        }
    }
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tab[TAB][TAB]) {
    printf("\nTABULEIRO\n\n");
    for (int i = 0; i < TAB; i++) {
        for (int j = 0; j < TAB; j++) {
            if (tab[i][j] == 0)
                printf("~ ");
            else if (tab[i][j] == 3)
                printf("N ");
            else if (tab[i][j] == 5)
                printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAB][TAB];
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Pontos de origem fixos das habilidades
    aplicarHabilidade(tabuleiro, cone, 1, 5);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);

    exibirTabuleiro(tabuleiro);

    return 0;
}
