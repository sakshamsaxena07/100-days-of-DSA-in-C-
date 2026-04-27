#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

int adj[MAX][MAX];
int indegree[MAX];
int present[MAX];
char queue[MAX];

// Topo sort
void topoSort() {
    int front = 0, rear = 0;

    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0)
            queue[rear++] = i;
    }

    while (front < rear) {
        int node = queue[front++];
        printf("%c ", node + 'a');

        for (int i = 0; i < MAX; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char words[n][100];

    for (int i = 0; i < n; i++)
        scanf("%s", words[i]);

    memset(adj, 0, sizeof(adj));
    memset(indegree, 0, sizeof(indegree));
    memset(present, 0, sizeof(present));

    // mark characters
    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    // build graph
    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        int len = strlen(w1) < strlen(w2) ? strlen(w1) : strlen(w2);

        for (int j = 0; j < len; j++) {
            if (w1[j] != w2[j]) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (!adj[u][v]) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }
                break;
            }
        }
    }

    topoSort();

    return 0;
}
