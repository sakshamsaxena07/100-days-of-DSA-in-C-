struct Node {
    int data;
    struct Node *left, *right;
};

// Flatten function
void flatten(struct Node* root) {
    struct Node* curr = root;

    while (curr) {
        if (curr->left) {
            // find rightmost of left subtree
            struct Node* temp = curr->left;
            while (temp->right)
                temp = temp->right;

            // connect
            temp->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
