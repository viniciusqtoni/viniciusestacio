#include <stdio.h>

int main() {

    /* ================================
       MOVIMENTO DA TORRE
       Estrutura utilizada: FOR
       Movimento: 5 casas para a direita
       ================================ */
    
    int casasTorre = 5;

    printf("Movimento da Torre:\n");

    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita\n");
    }

    printf("\n");

    /* ================================
       MOVIMENTO DO BISPO
       Estrutura utilizada: WHILE
       Movimento: 5 casas na diagonal
       (Cima e Direita)
       ================================ */

    int casasBispo = 5;
    int contadorBispo = 1;

    printf("Movimento do Bispo:\n");

    while (contadorBispo <= casasBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }

    printf("\n");

    /* ================================
       MOVIMENTO DA RAINHA
       Estrutura utilizada: DO-WHILE
       Movimento: 8 casas para a esquerda
       ================================ */

    int casasRainha = 8;
    int contadorRainha = 1;

    printf("Movimento da Rainha:\n");

    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha <= casasRainha);

    return 0;
}
