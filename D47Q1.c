void reverseQueue(int q[], int n) {
    int stack[100], top = -1;

    for (int i = 0; i < n; i++)
        stack[++top] = q[i];

    for (int i = 0; i < n; i++)
        q[i] = stack[top--];
}
