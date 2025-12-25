#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta de país
typedef struct {
    char nome[50];
    int populacao;          // em milhões
    float area;             // em milhões de km²
    float pib;              // em trilhões
    float densidade;        // habitantes por km²
} Carta;

// Função para exibir o menu de atributos
void mostrarMenu(int atributoBloqueado) {
    printf("\nEscolha um atributo para comparar:\n");

    if (atributoBloqueado != 1)
        printf("1 - População\n");
    if (atributoBloqueado != 2)
        printf("2 - Área\n");
    if (atributoBloqueado != 3)
        printf("3 - PIB\n");
    if (atributoBloqueado != 4)
        printf("4 - Densidade Demográfica\n");
}

// Função para obter o valor do atributo escolhido
float obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return 0;
    }
}

// Função para obter o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas pré-cadastradas
    Carta carta1 = {"Brasil", 213, 8.5, 2.1, 25.0};
    Carta carta2 = {"Canadá", 38, 9.9, 2.0, 4.0};

    int atributo1 = 0, atributo2 = 0;

    printf("=== SUPER TRUNFO - NIVEL MESTRE ===\n");
    printf("Comparação entre %s e %s\n", carta1.nome, carta2.nome);

    // Escolha do primeiro atributo
    mostrarMenu(0);
    printf("Digite a opção do primeiro atributo: ");
    scanf("%d", &atributo1);

    if (atributo1 < 1 || atributo1 > 4) {
        printf("Opção inválida! Encerrando o programa.\n");
        return 0;
    }

    // Escolha do segundo atributo (menu dinâmico)
    mostrarMenu(atributo1);
    printf("Digite a opção do segundo atributo: ");
    scanf("%d", &atributo2);

    if (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1) {
        printf("Opção inválida! Encerrando o programa.\n");
        return 0;
    }

    // Obtendo valores dos atributos
    float valor1_c1 = obterValor(carta1, atributo1);
    float valor1_c2 = obterValor(carta2, atributo1);

    float valor2_c1 = obterValor(carta1, atributo2);
    float valor2_c2 = obterValor(carta2, atributo2);

    // Soma dos atributos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;

    // Exibição dos resultados
    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
    printf("\nPaís 1: %s", carta1.nome);
    printf("\n%s: %.2f", nomeAtributo(atributo1), valor1_c1);
    printf("\n%s: %.2f", nomeAtributo(atributo2), valor2_c1);
    printf("\nSoma: %.2f\n", soma_c1);

    printf("\nPaís 2: %s", carta2.nome);
    printf("\n%s: %.2f", nomeAtributo(atributo1), valor1_c2);
    printf("\n%s: %.2f", nomeAtributo(atributo2), valor2_c2);
    printf("\nSoma: %.2f\n", soma_c2);

    // Decisão final usando operador ternário
    printf("\n=== VENCEDOR ===\n");
    soma_c1 == soma_c2 ? 
        printf("Empate!\n") :
        (soma_c1 > soma_c2 ? 
            printf("%s venceu!\n", carta1.nome) :
            printf("%s venceu!\n", carta2.nome));

    return 0;
}
