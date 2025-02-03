#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int getMin(struct TreeNode* node, int* min, int* val) {
    if (node) {
        getMin(node->left, min, val);

        int diff = abs(node->val - *val);
        if (diff < *min) {
            *min = diff;
        }
        *val = node->val;

        getMin(node->right, min, val);
    }

    return *min;
}

int getMinimumDifference(struct TreeNode* root) {
    int min = 100000;
    int val = 100000;
    return getMin(root, &min, &val);
}

// Solution
int solution(struct TreeNode *root) {
    int minDiff = 100000; // Initialize the minimum difference.
    int prevVal = 100000; // Initialize the previous node's value.

    // Helper function for in-order traversal.
    void inOrder(struct TreeNode * node) {
        if (node) {
            // Recursively traverse the left subtree.
            inOrder(node->left);

            // Calculate the absolute difference with the previous node's value.
            minDiff = abs(node->val - prevVal) < minDiff
                          ? abs(node->val - prevVal)
                          : minDiff;

            // Update the previous node's value.
            prevVal = node->val;

            // Recursively traverse the right subtree.
            inOrder(node->right);
        }
    }

    // Start the in-order traversal from the root.
    inOrder(root);

    return minDiff;
}
