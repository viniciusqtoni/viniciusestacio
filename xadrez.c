#include <stdio.h>

/*
=========================================================
 DESAFIO NÍVEL MESTRE - MOVIMENTOS DE XADREZ EM C
---------------------------------------------------------
 Peças implementadas:
 - Torre   -> Recursividade
 - Bispo   -> Recursividade + Loops Aninhados
 - Rainha  -> Recursividade
 - Cavalo  -> Loops Aninhados Complexos (movimento em L)

 Regras:
 - Não há entrada do usuário
 - Todos os valores são definidos no código
 - Impressão clara das direções
 - Código otimizado, legível e bem documentado
=========================================================
*/

/* =========================================================
   FUNÇÃO RECURSIVA - TORRE
   Move a Torre para cima, uma casa por chamada recursiva
========================================================= */
void moverTorre(int casas) {
    if (casas == 0) {
        return; // Caso base da recursão
    }

    printf("Cima\n");
    moverTorre(casas - 1); // Chamada recursiva
}

/* =========================================================
   FUNÇÃO RECURSIVA - RAINHA
   Move a Rainha na diagonal (Cima + Direita)
========================================================= */
void moverRainha(int casas) {
    if (casas == 0) {
        return; // Caso base
    }

    printf("Cima\n");
    printf("Direita\n");

    moverRainha(casas - 1); // Chamada recursiva
}

/* =========================================================
   FUNÇÃO - BISPO
   Usa:
   - Recursividade para controle de casas
   - Loops aninhados:
     Externo -> Vertical
     Interno -> Horizontal
========================================================= */
void moverBispo(int casas) {
    if (casas == 0) {
        return; // Caso base da recursão
    }

    // Loop externo: movimento vertical
    for (int vertical = 0; vertical < 1; vertical++) {

        // Loop interno: movimento horizontal
        for (int horizontal = 0; horizontal < 1; horizontal++) {
            printf("Cima\n");
            printf("Direita\n");
        }
    }

    moverBispo(casas - 1); // Chamada recursiva
}

/* =========================================================
   FUNÇÃO - CAVALO
   Movimento em "L":
   - Duas casas para cima
   - Uma casa para a direita

   Implementação com loops aninhados complexos,
   usando break e continue
========================================================= */
void moverCavalo() {
    int movimentoVertical;
    int movimentoHorizontal;

    // Loop para movimento vertical (2 casas para cima)
    for (movimentoVertical = 1; movimentoVertical <= 2; movimentoVertical++) {
        printf("Cima\n");

        // Quando completar as duas casas verticais
        if (movimentoVertical == 2) {

            // Loop horizontal (1 casa para a direita)
            for (movimentoHorizontal = 1; movimentoHorizontal <= 2; movimentoHorizontal++) {

                if (movimentoHorizontal > 1) {
                    break; // Garante apenas uma casa horizontal
                }

                printf("Direita\n");
            }
        }
    }
}

/* =========================================================
   FUNÇÃO PRINCIPAL
========================================================= */
int main() {

    // Definição das quantidades de casas (valores fixos)
    int casasTorre = 3;
    int casasBispo = 3;
    int casasRainha = 3;

    printf("=== MOVIMENTO DA TORRE ===\n");
    moverTorre(casasTorre);

    printf("\n=== MOVIMENTO DO BISPO ===\n");
    moverBispo(casasBispo);

    printf("\n=== MOVIMENTO DA RAINHA ===\n");
    moverRainha(casasRainha);

    printf("\n=== MOVIMENTO DO CAVALO ===\n");
    moverCavalo();

    return 0;
}
