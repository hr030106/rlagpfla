#include <stdio.h>
#include <stdbool.h> // bool Ÿ���� ����ϱ� ���� �ʿ�
#include <math.h> // sqrt �Լ��� ����ϱ� ���� �ʿ�

bool is_prime(int n) {
    // n�� 1���� �۰ų� ������ �Ҽ��� �ƴ�
    if (n <= 1) {
        return false;
    }

    // n�� 2�� ��쿡�� �Ҽ�
    if (n == 2) {
        return true;
    }

    // ¦���� �Ҽ��� �ƴ�
    if (n % 2 == 0) {
        return false;
    }

    // �����ٱ����� �˻� (�ð� ���⵵ ����)
    int sqrt_n = (int)sqrt(n);
    for (int i = 3; i <= sqrt_n; i += 2) { // Ȧ���� �˻�
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    // ����: 1���� 100������ �Ҽ� ���
    for (int number = 1; number <= 100; ++number) {
        if (is_prime(number)) {
            printf("%d ", number);
        }
    }
    printf("\n");

    return 0;
}
