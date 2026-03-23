struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

struct Node* build(int arr[], int n) {
    if (arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}
