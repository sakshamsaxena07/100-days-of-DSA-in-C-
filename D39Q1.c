int heap[100], size = 0;

void insert(int x) {
    heap[size] = x;
    int i = size++;

    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        int t = heap[i]; heap[i] = heap[(i-1)/2]; heap[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

int extractMin() {
    if (size == 0) return -1;

    int root = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, smallest = i;

        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;

        if (smallest == i) break;

        int t = heap[i]; heap[i] = heap[smallest]; heap[smallest] = t;
        i = smallest;
    }

    return root;
}
