#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int main() {
    int n, m, value;

    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insert(head1, value);
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insert(head2, value);
    }

    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while(head1 && head2) {
        if(head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    tail->next = (head1) ? head1 : head2;

    struct Node* temp = dummy.next;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
