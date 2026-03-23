struct Node {
    int data;
    struct Node* next;
};

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

int getIntersection(struct Node* h1, struct Node* h2) {
    int l1 = getLength(h1);
    int l2 = getLength(h2);

    int d = abs(l1 - l2);

    if (l1 > l2)
        while (d--) h1 = h1->next;
    else
        while (d--) h2 = h2->next;

    while (h1 && h2) {
        if (h1 == h2) return h1->data;
        h1 = h1->next;
        h2 = h2->next;
    }

    return -1; // No intersection
}
