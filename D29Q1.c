struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next) return head;

    int len = 1;
    struct Node* temp = head;

    while (temp->next) {
        temp = temp->next;
        len++;
    }

    temp->next = head; // make circular

    k = k % len;
    int steps = len - k;

    while (steps--) temp = temp->next;

    struct Node* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}
