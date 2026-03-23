int pq[100], size = 0;

void insert(int x) {
    pq[size++] = x;
}

int deleteMin() {
    if (size == 0) return -1;

    int min = 0;
    for (int i = 1; i < size; i++)
        if (pq[i] < pq[min]) min = i;

    int val = pq[min];
    pq[min] = pq[--size];
    return val;
}
