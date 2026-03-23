#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    
    while (head != NULL) {
        if (head->data == key)
            count++;
        head = head->next;
    }
    
    return count;
}
