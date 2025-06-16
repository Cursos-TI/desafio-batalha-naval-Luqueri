#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    
    for (int j = 2; j < 5; j++) tabuleiro[2][j] = 3;  
    for (int i = 5; i < 8; i++) tabuleiro[i][5] = 3;  

    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {
        {0,0,1,0,0},
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,1,0,0}
    };
    
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };

    int cone_origem[2] = {1, 4};      
    int cruz_origem[2] = {4, 4};      
    int octaedro_origem[2] = {7, 4};  

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (cone[i][j] == 1) {
                int linha = cone_origem[0] + i;
                int coluna = cone_origem[1] + (j - 2);  
                
                if (linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (cruz[i][j] == 1) {
                int linha = cruz_origem[0] + (i - 2);  
                int coluna = cruz_origem[1] + (j - 2);  
                
                if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (octaedro[i][j] == 1) {
                int linha = octaedro_origem[0] + (i - 2);  
                int coluna = octaedro_origem[1] + (j - 2);  
                
                if (linha >= 0 && linha < TAM_TABULEIRO && coluna >= 0 && coluna < TAM_TABULEIRO) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }

    printf("Tabuleiro com Habilidades Especiais:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}