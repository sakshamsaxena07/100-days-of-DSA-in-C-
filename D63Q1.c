#include <stdio.h>

#define MAX 1000

int visited[MAX];

// DFS
void dfs(int node, int n, int adj[MAX][MAX]) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, n, adj);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int adj[MAX][MAX];

    // input adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int start;
    scanf("%d", &start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(start, n, adj);

    return 0;
}
