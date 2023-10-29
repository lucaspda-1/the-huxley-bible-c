#include <stdio.h>

int main() {
    int n, i, j, k, count;
    int bets[100][10];
    int numbers[6];

    
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        printf("Aposta %d: ", i + 1);
        j = 0;
        while (1) {
            if (scanf("%d", &bets[i][j]) != 1) {
                break;
            }
            j++;
            char c = getchar();
            if (c == '\n') {
                break;
            }
        }
    }

    
    for (i = 0; i < 6; i++) {
        scanf("%d", &numbers[i]);
    }

    count = 0;
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < 6; j++) {
            int matched = 0;
            for (k = 0; k < 10; k++) {
                if (bets[i][k] == numbers[j]) {
                    matched = 1;
                    break;
                }
            }
            if (matched == 0) {
                break;
            }
            if (j == 5) {
                found = 1;
            }
        }
        if (found == 1) {
            count++;
        }
    }

    printf("Total de ganhadores: %d\n", count);

    return 0;
}

