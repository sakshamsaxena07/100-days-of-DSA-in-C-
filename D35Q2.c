int s1[1000], s2[1000];
int top1 = -1, top2 = -1;

void push(int x) {
    s1[++top1] = x;
}

int pop() {
    if (top2 == -1) {
        while (top1 != -1)
            s2[++top2] = s1[top1--];
    }
    return s2[top2--];
}

int peek() {
    if (top2 == -1) {
        while (top1 != -1)
            s2[++top2] = s1[top1--];
    }
    return s2[top2];
}

int empty() {
    return top1 == -1 && top2 == -1;
}
