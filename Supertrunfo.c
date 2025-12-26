#include <stdio.h>

int main() {
    // ===== Declaração das variáveis da Carta 1 =====
    char estado1[50], codigo1[10], nome1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int pontos1;

    // ===== Declaração das variáveis da Carta 2 =====
    char estado2[50], codigo2[10], nome2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int pontos2;

    // ===== Leitura dos dados da Carta 1 =====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado: ");
    scanf(" %[^\n]", estado1);

    printf("Codigo: ");
    scanf(" %[^\n]", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhoes): ");
    scanf("%f", &pib1);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos1);

    // ===== Leitura dos dados da Carta 2 =====
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado: ");
    scanf(" %[^\n]", estado2);

    printf("Codigo: ");
    scanf(" %[^\n]", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhoes): ");
    scanf("%f", &pib2);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos2);

    // ===== Cálculos =====
    float densidade1 = (float)populacao1 / area1;
    float densidade2 = (float)populacao2 / area2;

    float pibPerCapita1 = pib1 / (float)populacao1;
    float pibPerCapita2 = pib2 / (float)populacao2;

    float superPoder1 = (float)populacao1 + area1 + pib1 + pontos1 + pibPerCapita1 + (1.0f / densidade1);
    float superPoder2 = (float)populacao2 + area2 + pib2 + pontos2 + pibPerCapita2 + (1.0f / densidade2);

    // ===== Comparações =====
    int vencePopulacao = populacao1 > populacao2;
    int venceArea = area1 > area2;
    int vencePIB = pib1 > pib2;
    int vencePontos = pontos1 > pontos2;
    int venceDensidade = densidade1 < densidade2; // menor vence
    int vencePIBPerCapita = pibPerCapita1 > pibPerCapita2;
    int venceSuperPoder = superPoder1 > superPoder2;

    // ===== Exibição dos Resultados =====
    printf("\n=== Comparacao de Cartas ===\n\n");

    printf("Populacao: Carta %d venceu (%d)\n", vencePopulacao ? 1 : 2, vencePopulacao);
    printf("Area: Carta %d venceu (%d)\n", venceArea ? 1 : 2, venceArea);
    printf("PIB: Carta %d venceu (%d)\n", vencePIB ? 1 : 2, vencePIB);
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", vencePontos ? 1 : 2, vencePontos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", venceDensidade ? 1 : 2, venceDensidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", vencePIBPerCapita ? 1 : 2, vencePIBPerCapita);
    printf("Super Poder: Carta %d venceu (%d)\n", venceSuperPoder ? 1 : 2, venceSuperPoder);

    return 0;
}
