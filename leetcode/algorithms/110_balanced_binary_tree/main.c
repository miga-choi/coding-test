#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * DFS
 * 
 * Complexities:
 *   N - Number of `node`
 *   H - Height of `node`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
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
 * DFS
 * 
 * Complexities:
 *   N - Number of `node`
 *   H - Height of `node`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}

int checkHeight(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }

    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1) {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}

bool solution(struct TreeNode* root) {
    return checkHeight(root) != -1;
}
