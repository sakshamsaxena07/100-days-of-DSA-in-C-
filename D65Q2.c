#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int v;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// add edge
void addEdge(int u, int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = adj[u];
    adj[u] = node;

    node = (struct Node*)malloc(sizeof(struct Node));
    node->v = u;
    node->next = adj[v];
    adj[v] = node;
}

// DFS
int dfs(int node, int parent) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp) {
        int neigh = temp->v;

        if (!visited[neigh]) {
            if (dfs(neigh, node))
                return 1;
        }
        else if (neigh != parent) {
            return 1;
        }

        temp = temp->next;
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int cycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                cycle = 1;
                break;
            }
        }
    }

    if (cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
