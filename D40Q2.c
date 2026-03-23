void dailyTemperatures(int arr[], int n) {
    int stack[100], top = -1;
    int res[100] = {0};

    for (int i = 0; i < n; i++) {
        while (top != -1 && arr[i] > arr[stack[top]]) {
            int idx = stack[top--];
            res[idx] = i - idx;
        }
        stack[++top] = i;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", res[i]);
}
