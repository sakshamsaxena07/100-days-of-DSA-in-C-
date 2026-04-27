struct Node* queue[1000];

void rightSideView(struct Node* root) {
    if (!root) return;

    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            if (i == size - 1)
                printf("%d ", curr->data);

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }
    }
}
