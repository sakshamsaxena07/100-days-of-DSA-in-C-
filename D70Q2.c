#include <stdio.h>

#define INF 1e9

struct Edge {
    int u, v, w;
};

int findCheapestPrice(int n, int m, struct Edge edges[], int src, int dst, int k) {
    int dist[n], temp[n];

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    // relax edges k+1 times
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++)
            temp[j] = dist[j];

        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        for (int j = 0; j < n; j++)
            dist[j] = temp[j];
    }

    return (dist[dst] == INF) ? -1 : dist[dst];
}
