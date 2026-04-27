#include <stdio.h>

#define MAX 1000
#define INF 1e9

int minDistance(int dist[], int visited[], int n) {
    int min = INF, index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

int networkDelayTime(int n, int graph[MAX][MAX], int src) {
    int dist[MAX], visited[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        int u = minDistance(dist, visited, n + 1);
        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            return -1;
        if (dist[i] > max)
            max = dist[i];
    }

    return max;
}
