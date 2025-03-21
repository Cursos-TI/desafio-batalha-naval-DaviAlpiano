#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define LINHAS 10
#define COLUNAS 10
#define LINHASESP 3
#define COLUNASESP 5

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

     // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    int tabuleiro[LINHAS][COLUNAS] = {0};
    int coneEsp[LINHASESP][COLUNASESP] = {0};
    int cruzEsp[LINHASESP][COLUNASESP] = {0};
    int octaedroEsp[LINHASESP][COLUNASESP] = {0};

    // Posicionamento dos navios
    for(int i = 5; i <= 7; i++) {
        tabuleiro[0][i] = 3;
    }

    for(int i = 7; i <= 9; i++) {
        tabuleiro[i][3] = 3;
    }

    for(int i = 3, j = 2; i <= 5; i++, j++) {
        tabuleiro[i][j] = 3;
    }

    for(int i = 7, j = 7; i <= 9; i++, j++) {
        tabuleiro[i][j] = 3;
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    //Habilidades especiais
    //cone
    for(int i = 0; i < LINHASESP; i++) {
        int inicio = LINHASESP - i - 1;
        int fim = COLUNASESP - inicio;
        for(int j = inicio; j < fim; j++) {
            coneEsp[i][j] = 1;
        }
    }

    //cruz
    for(int i = 0; i < LINHASESP; i++) {
        for(int j = 0; j < COLUNASESP; j++) {
            if(i == 1 || j == 2) {
                cruzEsp[i][j] = 1;
            }
        }
    }

    //octaedro
    for(int i = 0; i < LINHASESP; i++) {
        for(int j = 0; j < COLUNASESP; j++) {
            if(i == 1 && j == 1 || i == 1 && j == 3 || j == 2 ) {
                octaedroEsp[i][j] = 1;
            }
        }
    }

    // Aplicando Habilidades
    //cone
    int startConeI = 0;
    int startConeJ = 0;
    for(int i = 0; i <  LINHASESP; i++) {
        for(int j = 0; j < COLUNASESP; j++) {
            if(coneEsp[i][j] == 1) {
                tabuleiro[startConeI + i][startConeJ + j] = 5;
            }
        }
    }

    //cruz
    int startCruzI = 5;
    int startCruzJ = 4;
    for(int i = 0; i < LINHASESP; i++) {
        for(int j = 0; j < COLUNASESP; j++) {
            if(cruzEsp[i][j] == 1) {
                tabuleiro[startCruzI + i][startCruzJ + j] = 5;
            }
        }
    }

    //octaedro
    int startOctI = 6;
    int startOctJ = 0;
    for(int i = 0; i < LINHASESP; i++) {
        for(int j = 0; j < COLUNASESP; j++) {
            if(octaedroEsp[i][j] == 1) {
                tabuleiro[startOctI + i][startOctJ + j] = 5;
            }
        }
    }

    // Exibição do tabuleiro
    printf("Tabuleiro:\n");
    printf("   A| B| C| D| E| F| G| H| I| J|\n");
    for (int i = 0; i < LINHAS; i++) {
        i + 1 == 10? printf("%d ", i + 1): printf("0%d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d| ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
