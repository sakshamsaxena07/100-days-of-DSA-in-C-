#include <stdio.h>

#define MAX 1000

int queue[MAX];

void topoSort(int n, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};

    // calculate indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j])
                indegree[j]++;
        }
    }

    int front = 0, rear = 0;

    // push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;

                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }
}
