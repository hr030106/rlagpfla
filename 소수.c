#include <stdio.h>
#include <stdbool.h> // bool 타입을 사용하기 위해 필요
#include <math.h> // sqrt 함수를 사용하기 위해 필요

bool is_prime(int n) {
    // n이 1보다 작거나 같으면 소수가 아님
    if (n <= 1) {
        return false;
    }

    // n이 2인 경우에는 소수
    if (n == 2) {
        return true;
    }

    // 짝수는 소수가 아님
    if (n % 2 == 0) {
        return false;
    }

    // 제곱근까지만 검사 (시간 복잡도 개선)
    int sqrt_n = (int)sqrt(n);
    for (int i = 3; i <= sqrt_n; i += 2) { // 홀수만 검사
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    // 예제: 1부터 100까지의 소수 출력
    for (int number = 1; number <= 100; ++number) {
        if (is_prime(number)) {
            printf("%d ", number);
        }
    }
    printf("\n");

    return 0;
}
