typedef struct {
    int stack[10000];
    int minStack[10000];
    int top;
} MinStack;

void push(MinStack* obj, int val) {
    obj->stack[++obj->top] = val;

    if (obj->top == 0 || val <= obj->minStack[obj->top - 1])
        obj->minStack[obj->top] = val;
    else
        obj->minStack[obj->top] = obj->minStack[obj->top - 1];
}

void pop(MinStack* obj) {
    obj->top--;
}

int topVal(MinStack* obj) {
    return obj->stack[obj->top];
}

int getMin(MinStack* obj) {
    return obj->minStack[obj->top];
}
