#include <stdio.h>

#define MAX 200

void dfs(int i, int n, int visited[], int graph[MAX][MAX]) {
    visited[i] = 1;

    for (int j = 0; j < n; j++) {
        if (graph[i][j] == 1 && !visited[j]) {
            dfs(j, n, visited, graph);
        }
    }
}

int findCircleNum(int graph[MAX][MAX], int n) {
    int visited[MAX] = {0};
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, visited, graph);
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int graph[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int result = findCircleNum(graph, n);

    printf("%d\n", result);

    return 0;
}
