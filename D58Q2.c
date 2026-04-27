struct Node* buildTreeHelper(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end) return NULL;

    struct Node* root = newNode(preorder[(*preIndex)++]);

    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == root->data)
            break;
    }

    root->left = buildTreeHelper(preorder, inorder, start, i - 1, preIndex);
    root->right = buildTreeHelper(preorder, inorder, i + 1, end, preIndex);

    return root;
}

struct Node* buildTree(int preorder[], int inorder[], int n) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, n - 1, &preIndex);
}
