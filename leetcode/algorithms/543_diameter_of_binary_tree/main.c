struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int returnDepth(struct TreeNode* node, int* max) {
    if (!node) {
        return 0;
    }
    int left = returnDepth(node->left, max);
    int right = returnDepth(node->right, max);

    if (left + right > *max) {
        *max = left + right;
    }

    return (left > right ? left : right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int max = 0;
    returnDepth(root, &max);
    return max;
}

// Solution
int rec(struct TreeNode* root, int* d) {
    if (!root) {
        return 0;
    }

    int ld = rec(root->left, d);
    int rd = rec(root->right, d);

    *d = *d > ld + rd ? *d : ld + rd;

    return (ld > rd ? ld : rd) + 1;
}

int solution(struct TreeNode* root) {
    int d = 0;
    rec(root, &d);
    return d;
}
