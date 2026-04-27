struct Node* buildHelper(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end) return NULL;

    struct Node* root = newNode(postorder[(*postIndex)--]);

    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == root->data)
            break;
    }

    root->right = buildHelper(inorder, postorder, i + 1, end, postIndex);
    root->left  = buildHelper(inorder, postorder, start, i - 1, postIndex);

    return root;
}

struct Node* buildTree(int inorder[], int postorder[], int n) {
    int postIndex = n - 1;
    return buildHelper(inorder, postorder, 0, n - 1, &postIndex);
}
