#define MAX 100
int q[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % MAX == front) return; // full

    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    q[rear] = x;
}

void dequeue() {
    if (front == -1) return;

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    int i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}
