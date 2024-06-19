#include <stdio.h>
#define MAX_SIZE 10 // 최대 행렬 크기 정의

void matrix_multiply(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
int main() {
    int size;

    printf("행렬의 크기를 입력하세요 (최대 10): ");
    scanf("%d", &size);

    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    printf("첫 번째 행렬을 입력하세요:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("두 번째 행렬을 입력하세요:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            scanf("%d", &mat2[i][j]);
        }
    }
    matrix_multiply(mat1, mat2, result, size);
    printf("결과 행렬:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
