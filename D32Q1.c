void process(int arr[], int n, int pops) {
    int stack[100], top = -1;

    for (int i = 0; i < n; i++)
        stack[++top] = arr[i];

    while (pops-- && top != -1)
        top--;

    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
}
