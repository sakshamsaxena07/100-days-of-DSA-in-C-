bool isPalindrome(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // find middle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half
    struct Node *prev = NULL, *curr = slow;
    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // compare
    while (prev) {
        if (head->data != prev->data)
            return false;
        head = head->next;
        prev = prev->next;
    }

    return true;
}
