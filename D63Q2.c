#include <stdio.h>

#define MAX 100

void dfs(int image[MAX][MAX], int m, int n, int r, int c, int oldColor, int newColor) {
    // boundary + condition check
    if (r < 0 || r >= m || c < 0 || c >= n)
        return;

    if (image[r][c] != oldColor)
        return;

    // change color
    image[r][c] = newColor;

    // explore 4 directions
    dfs(image, m, n, r + 1, c, oldColor, newColor);
    dfs(image, m, n, r - 1, c, oldColor, newColor);
    dfs(image, m, n, r, c + 1, oldColor, newColor);
    dfs(image, m, n, r, c - 1, oldColor, newColor);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int image[MAX][MAX];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &image[i][j]);

    int sr, sc, color;
    scanf("%d %d %d", &sr, &sc, &color);

    int oldColor = image[sr][sc];

    // important edge case
    if (oldColor != color)
        dfs(image, m, n, sr, sc, oldColor, color);

    // print result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", image[i][j]);
        printf("\n");
    }

    return 0;
}
