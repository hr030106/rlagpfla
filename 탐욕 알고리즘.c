#include <stdio.h>

void coinChange(int coins[], int m, int V) {
    int result = 0;
    for (int i = 0; i < m; i++) {
        if (coins[i] <= V) {
            result += V / coins[i];  // �ش� �������� ��ȯ ������ ����
            V = V % coins[i];  // ������ �ݾ�
        }
    }

    printf("Minimum number of coins: %d\n", result);
}

int main() {
    int coins[] = {1, 5, 10, 25};  // ������ ����
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 63;  // ��ȯ�� �ݾ�

    coinChange(coins, m, V);

    return 0;
}
