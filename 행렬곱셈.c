#include <stdio.h>
#define MAX_SIZE 10 // �ִ� ��� ũ�� ����

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

    printf("����� ũ�⸦ �Է��ϼ��� (�ִ� 10): ");
    scanf("%d", &size);

    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    printf("ù ��° ����� �Է��ϼ���:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("�� ��° ����� �Է��ϼ���:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            scanf("%d", &mat2[i][j]);
        }
    }
    matrix_multiply(mat1, mat2, result, size);
    printf("��� ���:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
