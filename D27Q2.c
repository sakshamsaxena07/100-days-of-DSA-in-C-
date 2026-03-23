void removeLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break;
    }

    if (slow != fast) return; // no loop

    slow = head;

    // Find start of loop
    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL; // break loop
}
