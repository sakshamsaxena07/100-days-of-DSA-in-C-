typedef struct {
    int arr[1000];
    int front, rear, size, cap;
} MyCircularDeque;

void init(MyCircularDeque* obj, int k) {
    obj->front = 0;
    obj->rear = -1;
    obj->size = 0;
    obj->cap = k;
}

int isFull(MyCircularDeque* obj) {
    return obj->size == obj->cap;
}

int isEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

int insertFront(MyCircularDeque* obj, int val) {
    if (isFull(obj)) return 0;
    obj->front = (obj->front - 1 + obj->cap) % obj->cap;
    obj->arr[obj->front] = val;
    obj->size++;
    if (obj->size == 1) obj->rear = obj->front;
    return 1;
}

int insertLast(MyCircularDeque* obj, int val) {
    if (isFull(obj)) return 0;
    obj->rear = (obj->rear + 1) % obj->cap;
    obj->arr[obj->rear] = val;
    obj->size++;
    return 1;
}
