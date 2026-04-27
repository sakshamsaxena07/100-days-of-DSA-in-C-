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

// add edge u -> v
void addEdge(int u, int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->next = adj[u];
    adj[u] = node;
}

// DFS
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
            return 1;
        }

        temp = temp->next;
    }

    recStack[node] = 0;
    return 0;
}

int canFinish(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 0; // cycle exists
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        // b -> a (prerequisite)
        addEdge(b, a);
    }

    if (canFinish(n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
