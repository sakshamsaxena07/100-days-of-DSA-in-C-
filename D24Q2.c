#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* removeElements(struct Node* head, int val) {
    struct Node dummy;
    dummy.next = head;

    struct Node* curr = &dummy;

    while (curr->next != NULL) {
        if (curr->next->data == val) {
            struct Node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;
}
