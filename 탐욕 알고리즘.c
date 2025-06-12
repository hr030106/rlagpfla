#include <stdio.h>

void coinChange(int coins[], int m, int V) {
    int result = 0;
    for (int i = 0; i < m; i++) {
        if (coins[i] <= V) {
            result += V / coins[i];  // 해당 동전으로 교환 가능한 개수
            V = V % coins[i];  // 나머지 금액
        }
    }

    printf("Minimum number of coins: %d\n", result);
}

int main() {
    int coins[] = {1, 5, 10, 25};  // 동전의 종류
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 63;  // 교환할 금액

    coinChange(coins, m, V);

    return 0;
}
