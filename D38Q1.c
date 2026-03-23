int dq[100], front = -1, rear = -1;

void push_front(int x) {
    if (front == -1) front = rear = 0;
    else front--;
    dq[front] = x;
}

void push_back(int x) {
    if (rear == -1) front = rear = 0;
    else rear++;
    dq[rear] = x;
}

void pop_front() {
    if (front <= rear) front++;
}

void pop_back() {
    if (rear >= front) rear--;
}
