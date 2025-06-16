#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    
    int ocupacao[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    
    int navios[4][3] = {
        {2, 4, 'H'},  
        {5, 3, 'V'},  
        {1, 1, 'C'},  
        {3, 8, 'D'}   
    };

    for (int n = 0; n < 4; n++) {
        int linha = navios[n][0];
        int coluna = navios[n][1];
        char direcao = navios[n][2];
        
        for (int k = 0; k < TAM_NAVIO; k++) {
            int pos_i = linha;
            int pos_j = coluna;
            
            switch (direcao) {
                case 'H': 
                    pos_j += k;
                    break;
                case 'V': 
                    pos_i += k;
                    break;
                case 'C': 
                    pos_i += k;
                    pos_j += k;
                    break;
                case 'D': 
                    pos_i += k;
                    pos_j -= k;
                    break;
            }
            
            if (pos_i < 0 || pos_i >= TAM_TABULEIRO || pos_j < 0 || pos_j >= TAM_TABULEIRO) {
                printf("Erro: Navio %d fora dos limites do tabuleiro na posicao (%d,%d)!\n", n+1, pos_i, pos_j);
                return 1;
            }
            
            if (ocupacao[pos_i][pos_j] == 1) {
                printf("Erro: Sobrepopsicao detectada no navio %d na posicao (%d,%d)!\n", n+1, pos_i, pos_j);
                return 1;
            }
        }
        
        for (int k = 0; k < TAM_NAVIO; k++) {
            int pos_i = linha;
            int pos_j = coluna;
            
            switch (direcao) {
                case 'H': pos_j += k; break;
                case 'V': pos_i += k; break;
                case 'C': pos_i += k; pos_j += k; break;
                case 'D': pos_i += k; pos_j -= k; break;
            }
            
            ocupacao[pos_i][pos_j] = 1;
    }
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (ocupacao[i][j] == 1) {
                tabuleiro[i][j] = 3;
            }
        }
    }
    
    printf("Tabuleiro de Batalha Naval com Navios Diagonais:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}