#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int v;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int recStack[MAX];
int stack[MAX], top = -1;

// add edge u -> v
void addEdge(int u, int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = adj[u];
    adj[u] = node;
}

// DFS with cycle detection
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];
    while (temp) {
        int neigh = temp->v;

        if (!visited[neigh]) {
            if (dfs(neigh))
                return 1;
        }
        else if (recStack[neigh]) {
            return 1; // cycle
        }

        temp = temp->next;
    }

    recStack[node] = 0;
    stack[++top] = node;
    return 0;
}

int findOrder(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        adj[i] = NULL;
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        // b -> a
        addEdge(b, a);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("Cycle detected → no valid order\n");
                return 0;
            }
        }
    }

    // print topo order
    while (top >= 0)
        printf("%d ", stack[top--]);

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    findOrder(n);

    return 0;
}
