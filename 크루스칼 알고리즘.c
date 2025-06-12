#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// ���� ����ü ����
struct Edge {
    int src, dest, weight;
};

// Union-Find �ڷᱸ�� (����Ŭ�� üũ�ϱ� ����)
int parent[MAX_VERTICES];
int rank[MAX_VERTICES];

// �θ� ��带 ã�� �Լ� (��� ���� ��� ���)
int find(int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent[i]);
}

// �� ������ ��ġ�� �Լ� (Union by rank ��� ���)
void unionSets(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if (xroot != yroot) {
        if (rank[xroot] < rank[yroot]) {
            parent[xroot] = yroot;
        } else if (rank[xroot] > rank[yroot]) {
            parent[yroot] = xroot;
        } else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
}

// ������ ����ġ �������� �������� ����
int compare(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal �˰������� �ּ� ���� Ʈ�� ���ϱ�
void kruskal(struct Edge edges[], int E, int V) {
    // �������� ����ġ �������� �������� ����
    qsort(edges, E, sizeof(edges[0]), compare);

    // �θ� ��� �ʱ�ȭ
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    printf("Edges in the Minimum Spanning Tree:\n");

    int mstWeight = 0;
    for (int i = 0; i < E; i++) {
        int x = find(edges[i].src);
        int y = find(edges[i].dest);

        // ����Ŭ�� �߻����� �ʴ� ��쿡�� ������ MST�� �߰�
        if (x != y) {
            printf("%d - %d : %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(x, y);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    // �׷����� ������ (src, dest, weight)
    struct Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    int V = 4;  // ������ ��
    int E = 5;  // ������ ��

    // Kruskal �˰��� ����
    kruskal(edges, E, V);

    return 0;
}
