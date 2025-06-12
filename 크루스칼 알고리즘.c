#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// 간선 구조체 정의
struct Edge {
    int src, dest, weight;
};

// Union-Find 자료구조 (사이클을 체크하기 위한)
int parent[MAX_VERTICES];
int rank[MAX_VERTICES];

// 부모 노드를 찾는 함수 (경로 압축 기법 사용)
int find(int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent[i]);
}

// 두 집합을 합치는 함수 (Union by rank 기법 사용)
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

// 간선의 가중치 기준으로 오름차순 정렬
int compare(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal 알고리즘으로 최소 신장 트리 구하기
void kruskal(struct Edge edges[], int E, int V) {
    // 간선들을 가중치 기준으로 오름차순 정렬
    qsort(edges, E, sizeof(edges[0]), compare);

    // 부모 노드 초기화
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    printf("Edges in the Minimum Spanning Tree:\n");

    int mstWeight = 0;
    for (int i = 0; i < E; i++) {
        int x = find(edges[i].src);
        int y = find(edges[i].dest);

        // 사이클이 발생하지 않는 경우에만 간선을 MST에 추가
        if (x != y) {
            printf("%d - %d : %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(x, y);
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    // 그래프의 간선들 (src, dest, weight)
    struct Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    int V = 4;  // 정점의 수
    int E = 5;  // 간선의 수

    // Kruskal 알고리즘 실행
    kruskal(edges, E, V);

    return 0;
}
