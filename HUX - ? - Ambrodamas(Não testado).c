

1 de 1.101
Documento de Lucas Pereira
Caixa de entrada

LUCAS PEREIRA DE ARAUJO <lpa4@aluno.ifal.edu.br>
Anexos
16:52 (há 5 minutos)
para mim

 Um anexo
  •  Anexos verificados pelo Gmail
#include <stdio.h>

#define TAM 10

void movements(char m[TAM][TAM], char player[2], char adversary[2], int move, int capture) {
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            if(m[i][j] == player[0]) {
                if(player[0] == '1') {
                    if(m[i + 1][j + 1] == ' ') move++;
                    if(m[i - 1][j + 1] == ' ') move++;
                }
                else if(player[0] == '2') {
                    if(m[i - 1][j - 1] == ' ') move++;
                    if(m[i + 1][j - 1] == ' ') move++;
                }

                if((m[i + 1][j + 1] == adversary[0]) || (m[i + 1][j + 1] == adversary[1])) {
                    if(m[i + 2][j + 2] == ' ') {
                        move++;
                        capture++;
                    }
                }
                if((m[i - 1][j + 1] == adversary[0]) || (m[i - 1][j + 1] == adversary[1])) {
                    if(m[i - 2][j + 2] == ' ') {
                        move++;
                        capture++;
                    }
                }
                if((m[i - 1][j - 1] == adversary[0]) || (m[i - 1][j - 1] == adversary[1])) {
                    if(m[i - 2][j - 2] == ' ') {
                        move++;
                        capture++;
                    }
                }
                if((m[i + 1][j - 1] == adversary[0]) || (m[i + 1][j - 1] == adversary[1])) {
                    if(m[i + 2][j - 2] == ' ') {
                        move++;
                        capture++;
                    }
                }
            }
            else if(m[i][j] == player[1]) {
                int k = 1;

                while((i + k) < TAM && (j + k) < TAM) {
                    if(m[i + k][j + k] == player[0] || m[i + k][i + j] == player[1])
                        break;
                    else {
                        if(m[i + k][j + k] == ' ') move++;

                        if(m[i + k][j + k] == adversary[0] || m[i + k][j + k] == adversary[1]) {
                            if(m[i + k + 1][j + k + 1] == ' ') {
                                move++;
                                capture++;

                                k++;
                            }
                        }
                    }

                    k++;                        
                }

                k = 1;
                while((i - k) >= 0 && (j - k) >= 0) {
                    if(m[i - k][j - k] == player[0] || m[i - k][i - j] == player[1])
                        break;
                    else {
                        if(m[i - k][j - k] == ' ') move++;

                        if(m[i - k][j - k] == adversary[0] || m[i - k][j - k] == adversary[1]) {
                            if(m[i - k - 1][j - k - 1] == ' ') {
                                move++;
                                capture++;

                                k++;
                            }
                        }
                    }

                    k++;                        
                }

                k = 1;
                while((i + k) < TAM && (j - k) >= 0) {
                    if(m[i + k][j - k] == player[0] || m[i + k][j - k] == player[1])
                        break;
                    else {
                        if(m[i + k][j - k] == ' ') move++;

                        if(m[i + k][j - k] == adversary[0] || m[i + k][j - k] == adversary[1]) {
                            if(m[i + k + 1][j - k - 1] == ' ') {
                                move++;
                                capture++;

                                k++;
                            }
                        }
                    }

                    k++;                        
                }

                k = 1;
                while((i - k) >= 0 && (j + k) < TAM) {
                    if(m[i - k][j + k] == player[0] || m[i - k][i + j] == player[1])
                        break;
                    else {
                        if(m[i - k][j + k] == ' ') move++;

                        if(m[i - k][j + k] == adversary[0] || m[i - k][j + k] == adversary[1]) {
                            if(m[i - k - 1][j + k + 1] == ' ') {
                                move++;
                                capture++;

                                k++;
                            }
                        }
                    }

                    k++;                        
                }
            }
        }
    }

    printf("Jogadas possiveis: %d\n", move);
    printf("Capturas possiveis: %d\n", capture);
}

int main() {
    char matriz[TAM][TAM];
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++)
            scanf("%c", &matriz[i][j]);

        getchar();
    }

    int player;
    scanf("%d", &player);

    char player1[] = {'1', '*'};
    char player2[] = {'2', '#'};

    if(player == 1)
        movements(matriz, player1, player2, 0, 0);
    else if(player == 2)
        movements(matriz, player2, player1, 0, 0);

    return 0;
}
