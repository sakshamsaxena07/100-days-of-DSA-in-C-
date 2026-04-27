struct Node* queue[1000];

void zigzagLevelOrder(struct Node* root) {
    if (!root) return;

    int front = 0, rear = 0;
    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int temp[size];

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            int index = leftToRight ? i : (size - 1 - i);
            temp[index] = curr->data;

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        // Print as list format
        printf("[");
        for (int i = 0; i < size; i++) {
            printf("%d", temp[i]);
            if (i < size - 1) printf(", ");
        }
        printf("]\n");

        leftToRight = !leftToRight;
    }
}
