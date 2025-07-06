#include <limits.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderTraversal(struct TreeNode* node, int* vals, int* index) {
    if (!node) {
        return;
    }

    inorderTraversal(node->left, vals, index);
    vals[++(*index)] = node->val;
    inorderTraversal(node->right, vals, index);
}

int minDiffInBST(struct TreeNode* root) {
    int vals[100];
    int index = -1;

    inorderTraversal(root, vals, &index);

    int min = 10e5;

    for (int i = 0; i < index; i++) {
        int diff = vals[i + 1] - vals[i];

        if (diff < min) {
            min = diff;
        }
    }

    return min;
}
