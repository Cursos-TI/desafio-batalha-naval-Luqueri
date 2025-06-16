#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    
    int navio_horizontal[] = {2, 4};
    int navio_vertical[] = {5, 3};   
    if (navio_horizontal[1] + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro!\n");
        return 1; 
    }
    
    if (navio_vertical[0] + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro!\n");
        return 1; 
    }
    
    if (navio_horizontal[0] >= navio_vertical[0] && 
        navio_horizontal[0] <= navio_vertical[0] + TAM_NAVIO - 1 &&
        navio_vertical[1] >= navio_horizontal[1] && 
        navio_vertical[1] <= navio_horizontal[1] + TAM_NAVIO - 1) {
        printf("Erro: Navios se sobrepoem no tabuleiro!\n");
        return 1;
    }

    for (int col = 0; col < TAM_NAVIO; col++) {
        tabuleiro[navio_horizontal[0]][navio_horizontal[1] + col] = 3;
    }
    
    for (int lin = 0; lin < TAM_NAVIO; lin++) {
        tabuleiro[navio_vertical[0] + lin][navio_vertical[1]] = 3;
    }

    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}