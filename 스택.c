#include <stdio.h>
#include <stdlib.h>
int SIZE;
int arr[4];
int top = -1;

void push(int input) {
  if (top == 3) {
    printf("��ȭ�����Դϴ�\n");
  } else {
    top++;
    arr[top] = input;
  }
}
void pop() {
  if (top == -1) {
    printf("��������Դϴ�\n");
  } else {
    arr[top] = 0;
    top--;
  }
}
int main(void) {

  int mode;
  int input;

  while (1) {
    printf("1.���� 2.����: ");
    printf("\n");
    scanf("%d", &mode);

    if (mode == 1) {
        printf("������ ���� �Է��ϼ���: ");
        scanf("%d", &input);
        push(input);


    }  if (mode == 2) {
      pop();
    }

    for (int i = 0; i<4; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }
}
