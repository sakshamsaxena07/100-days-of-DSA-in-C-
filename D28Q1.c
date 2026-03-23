struct Node {
    int data;
    struct Node* next;
};

struct Node* createCircular(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;

    struct Node* temp = head;

    for (int i = 1; i < n; i++) {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
    }

    temp->next = head; // circular

    return head;
}

void displayCircular(struct Node* head) {
    if (!head) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
