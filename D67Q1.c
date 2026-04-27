#include <stdio.h>

#define MAX 1000

int visited[MAX];
int stack[MAX];
int top = -1;

// DFS
void dfs(int node, int n, int adj[MAX][MAX]) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n, adj);
        }
    }

    stack[++top] = node; // push after recursion
}

void topoSort(int n, int adj[MAX][MAX]) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, n, adj);
    }

    // print in reverse stack
    while (top >= 0)
        printf("%d ", stack[top--]);
}

int main() {
    int n;
    scanf("%d", &n);

    int adj[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    topoSort(n, adj);

    return 0;
}
