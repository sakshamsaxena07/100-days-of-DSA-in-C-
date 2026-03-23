void maxSlidingWindow(int arr[], int n, int k) {
    int dq[100], front = 0, rear = -1;

    for (int i = 0; i < n; i++) {

        // remove out of window
        if (front <= rear && dq[front] <= i-k)
            front++;

        // remove smaller elements
        while (front <= rear && arr[dq[rear]] <= arr[i])
            rear--;

        dq[++rear] = i;

        if (i >= k-1)
            printf("%d ", arr[dq[front]]);
    }
}
