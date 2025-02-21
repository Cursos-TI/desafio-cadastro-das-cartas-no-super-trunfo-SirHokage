#include <stdio.h>

#define MAX_ESTADOS 8
#define MAX_CIDADES 4
#define MAX_CARTAS (MAX_ESTADOS * MAX_CIDADES) // responsaveis por definir o limite maximo de Estadis, Cidades e cartas.

typedef struct {
    char codigo[4];
    int populacao;
    int area;
    int pib;
    int pontosTuristicos;
} Carta; // Estrutura das cartas, definindo os parametros que o curso pediu.

void cadastrarCartas(Carta cartas[], int *quantidade) { // responsavel por cadastrar as cartas com base nas escolhas do jogador.
    const char estados[] = "ABCDEFGH"; // lista dos estados
    for (int i = 0; i < MAX_ESTADOS && *quantidade < MAX_CARTAS; i++) {
        for (int j = 0; j < MAX_CIDADES && *quantidade < MAX_CARTAS; j++) {
            snprintf(cartas[*quantidade].codigo, sizeof(cartas[*quantidade].codigo), "%c%02d", estados[i], j + 1);
            printf("\nCadastro da carta %s:\nPopulação (em milhares): ", cartas[*quantidade].codigo);
            scanf("%d", &cartas[*quantidade].populacao);
            printf("Área (em km²): ");
            scanf("%d", &cartas[*quantidade].area);
            printf("PIB (em milhões de dólares): ");
            scanf("%d", &cartas[*quantidade].pib);
            printf("Número de pontos turísticos: ");
            scanf("%d", &cartas[*quantidade].pontosTuristicos);
            (*quantidade)++;
        }
    }
}

void exibirCartas(Carta cartas[], int quantidade) { // responsavel por mostrar as cartas cadastradas.
    for (int i = 0; i < quantidade; i++) {
        printf("\nCarta %s:\nPopulação: %d mil\nÁrea: %d km²\nPIB: %d milhões de dólares\nPontos turísticos: %d\n",
               cartas[i].codigo, cartas[i].populacao, cartas[i].area, cartas[i].pib, cartas[i].pontosTuristicos);
    }
}

int main() { // função principal que inicializa o código e chama as funções de cadastro e de exibir;
    Carta cartas[MAX_CARTAS];
    int quantidade = 0;

    printf("Desafio de criar um sistema de cadastrar cartas Super Triunfo!\n");
    cadastrarCartas(cartas, &quantidade);
    exibirCartas(cartas, quantidade);

    return 0;
}
