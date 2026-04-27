#include <stdio.h>

#define MAX 1000

int visited[MAX];
int queue[MAX];

void bfs(int start, int n, int adj[MAX][MAX]) {
    int front = 0, rear = 0;

    // enqueue start
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int adj[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int start;
    scanf("%d", &start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    bfs(start, n, adj);

    return 0;
}
