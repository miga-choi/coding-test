#include <stdbool.h>
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
int getMaxDepth(struct TreeNode* node) {
    if (!node) {
        return 0;
    }

    int left_depth = getMaxDepth(node->left);
    if (left_depth < 0) {
        return -1;
    }

    int right_depth = getMaxDepth(node->right);
    if (right_depth < 0) {
        return -1;
    }

    if (abs(left_depth - right_depth) > 1) {
        return -1;
    }

    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

bool isBalanced(struct TreeNode* root) {
  return getMaxDepth(root) != -1;
}


// Solution
/**
 * Recursion: DFS
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}

int check_balance_and_get_height(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }

    int leftHeight = check_balance_and_get_height(node->left);
    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = check_balance_and_get_height(node->right);
    if (rightHeight == -1) {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}

bool solution(struct TreeNode* root) {
    return check_balance_and_get_height(root) != -1;
}
