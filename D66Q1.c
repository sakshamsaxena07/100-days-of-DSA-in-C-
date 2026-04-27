#include <stdio.h>

#define MAX 1000

int visited[MAX];
int recStack[MAX];

// DFS
int dfs(int node, int n, int adj[MAX][MAX]) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, n, adj))
                    return 1;
            }
            else if (recStack[i]) {
                return 1; // cycle
            }
        }
    }

    recStack[node] = 0;
    return 0;
}

int hasCycle(int n, int adj[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n, adj))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int adj[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    if (hasCycle(n, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
