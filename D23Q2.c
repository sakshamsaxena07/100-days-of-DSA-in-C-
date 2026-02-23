#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, pos, value;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode, *cycleNode = NULL;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;

        if(i == 0)
            cycleNode = newNode;
    }

    scanf("%d", &pos);

    if(pos != -1) {
        temp->next = cycleNode;  // simple cycle for demo
    }

    struct Node *slow = head, *fast = head;
    int hasCycle = 0;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            hasCycle = 1;
            break;
        }
    }

    if(hasCycle)
        printf("true");
    else
        printf("false");

    return 0;
}
