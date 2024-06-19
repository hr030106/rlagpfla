#include <stdio.h>
#include <stdlib.h>

#define MAX 7
#define false 0
#define true 1

// �׷����� ��� ���� ����
struct Node {
    int data;
    struct Node* next;
};

// ���� ���� ����
typedef struct {
    int items[MAX];
    int top;
} Stack;

struct Node* graph[MAX];
int visited[MAX] = {false};

// ���� �ʱ�ȭ
void initStack(Stack* s) {
    s->top = -1;
}

// ������ ����ִ��� Ȯ��
int isEmpty(Stack* s) {
    return s->top == -1;
}

// ���ÿ� ��� �߰�
void push(Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->items[++s->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// ���ÿ��� ��� ����
int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

// �׷����� ��� �߰�
void addNode(int vertex, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = graph[vertex];
    graph[vertex] = newNode;
}

// DFS �Լ� ����
void dfs(int start) {
    Stack stack;
    initStack(&stack);
    push(&stack, start);

    while (!isEmpty(&stack)) {
        int vertex = pop(&stack);

        if (!visited[vertex]) {
            printf("%c ", vertex + 'a');
            visited[vertex] = true;

            struct Node* temp = graph[vertex];
            while (temp != NULL) {
                if (!visited[temp->data]) {
                    push(&stack, temp->data);
                }
                temp = temp->next;
            }
        }
    }
}

int main() {
    addNode(0, 1); // a -> b
    addNode(1, 0); // b -> a
    addNode(1, 2); // b -> c
    addNode(1, 4); // b -> e
    addNode(2, 1); // c -> b
    addNode(2, 3); // c -> d
    addNode(3, 2); // d -> c
    addNode(4, 1); // e -> b
    addNode(4, 5); // e -> f
    addNode(4, 6); // e -> g
    addNode(5, 4); // f -> e
    addNode(6, 4); // g -> e

    printf("���̿켱Ž�� ���: ");
    dfs(0); // a ��忡�� DFS ����

    return 0;
}
