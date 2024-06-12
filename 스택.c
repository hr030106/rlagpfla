#include <stdio.h>
#include <stdlib.h>
int SIZE;
int arr[4];
int top = -1;

void push(int input) {
  if (top == 3) {
    printf("포화상태입니다\n");
  } else {
    top++;
    arr[top] = input;
  }
}
void pop() {
  if (top == -1) {
    printf("공백상태입니다\n");
  } else {
    arr[top] = 0;
    top--;
  }
}
int main(void) {

  int mode;
  int input;

  while (1) {
    printf("1.삽입 2.삭제: ");
    printf("\n");
    scanf("%d", &mode);

    if (mode == 1) {
        printf("삽입할 수를 입력하세요: ");
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
