#include <limits.h>
#include <stdbool.h>
#include <stddef.h>

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
bool helper(struct TreeNode* node, long min_val, long max_val) {
    if (!node) {
        return true;
    }

    if ((long)node->val <= min_val || (long)node->val >= max_val) {
        return false;
    }

    return helper(node->left, min_val, node->val) &&
           helper(node->right, node->val, max_val);
}

bool isValidBST(struct TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}


// Solution
/**
 * Recursion
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 */
bool isValidBST_helper(struct TreeNode* node, long long min_val, long long max_val) {
    if (node == NULL) {
        return true;
    }

    if ((long long)node->val <= min_val || (long long)node->val >= max_val) {
        return false;
    }

    return isValidBST_helper(node->left, min_val, node->val) &&
           isValidBST_helper(node->right, node->val, max_val);
}

bool solution(struct TreeNode* root) {
    return isValidBST_helper(root, LONG_MIN, LONG_MAX);
}
