#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Delete first occurrence
struct Node* deleteFirst(struct Node* head, int key) {
    if (head == NULL) return head;

    // If head needs to be deleted
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    
    while (curr->next != NULL && curr->next->data != key) {
        curr = curr->next;
    }

    // If key found
    if (curr->next != NULL) {
        struct Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    return head;
}
