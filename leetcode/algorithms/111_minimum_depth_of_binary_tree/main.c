#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Recursion: DFS
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 */
int minDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int left_depth = minDepth(root->left);
    int right_depth = minDepth(root->right);

    if (!left_depth || !right_depth) {
        return (left_depth > right_depth ? left_depth : right_depth) + 1;
    }

    return (left_depth < right_depth ? left_depth : right_depth) + 1;
}


// Solution
/**
 * Recursion: DFS
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 */
int min(int a, int b) {
    return (a < b) ? a : b;
}

int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    if (leftDepth == 0 || rightDepth == 0) {
        return 1 + leftDepth + rightDepth;
    } else {
        return 1 + min(leftDepth, rightDepth);
    }
}
