#include <stdio.h>

#define MAX 1000

typedef struct {
    int r, c;
} Node;

Node queue[MAX * MAX];

int orangesRotting(int grid[MAX][MAX], int m, int n) {
    int front = 0, rear = 0;
    int fresh = 0, minutes = 0;

    // push all rotten oranges
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Node){i, j};
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (front < rear && fresh > 0) {
        int size = rear - front;
        minutes++;

        for (int i = 0; i < size; i++) {
            Node curr = queue[front++];

            for (int d = 0; d < 4; d++) {
                int nr = curr.r + directions[d][0];
                int nc = curr.c + directions[d][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    queue[rear++] = (Node){nr, nc};
                    fresh--;
                }
            }
        }
    }

    return (fresh == 0) ? minutes : -1;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int grid[MAX][MAX];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);

    printf("%d\n", orangesRotting(grid, m, n));

    return 0;
}
