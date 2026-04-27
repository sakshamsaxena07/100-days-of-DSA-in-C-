#include <stdio.h>

#define MAX 1000

int visited[MAX];

// DFS
void dfs(int room, int n, int rooms[MAX][MAX], int size[]) {
    visited[room] = 1;

    for (int i = 0; i < size[room]; i++) {
        int next = rooms[room][i];
        if (!visited[next]) {
            dfs(next, n, rooms, size);
        }
    }
}

// Main check
int canVisitAllRooms(int n, int rooms[MAX][MAX], int size[]) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(0, n, rooms, size);

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int rooms[MAX][MAX];
    int size[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &size[i]);
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    if (canVisitAllRooms(n, rooms, size))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
