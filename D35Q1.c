#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}
