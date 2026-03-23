struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head;

    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

struct ListNode* addTwoForward(struct ListNode* l1, struct ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    struct ListNode* res = addTwoNumbers(l1, l2);

    return reverse(res);
}
