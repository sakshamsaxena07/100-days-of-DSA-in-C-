struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* temp = &dummy;
    dummy.next = NULL;

    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }

        carry = sum / 10;

        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;

        temp->next = node;
        temp = temp->next;
    }

    return dummy.next;
}
