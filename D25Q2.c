struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;

    // Step 1: Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: Find start
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}
