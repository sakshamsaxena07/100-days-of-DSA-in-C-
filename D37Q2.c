int heap[1000], size = 0, k;

void heapifyUp(int i) {
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        int t = heap[i]; heap[i] = heap[(i-1)/2]; heap[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int l = 2*i+1, r = 2*i+2;

    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        int t = heap[i]; heap[i] = heap[smallest]; heap[smallest] = t;
        heapifyDown(smallest);
    }
}

int add(int val) {
    if (size < k) {
        heap[size++] = val;
        heapifyUp(size-1);
    } else if (val > heap[0]) {
        heap[0] = val;
        heapifyDown(0);
    }
    return heap[0];
}
