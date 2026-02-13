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
 * 
 * Complexities:
 *   N - Size of `node`
 *   H - Height of `node`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
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
 * Recursive with Range
 * 
 * Complexities:
 *   N - Size of `node`
 *   H - Height of `node`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
 bool validate(struct TreeNode* node, long long min, long long max) {
    if (node == NULL) {
        return true;
    }

    if (node->val <= min || node->val >= max) {
        return false;
    }

    return validate(node->left, min, node->val) && validate(node->right, node->val, max);
}

bool solution(struct TreeNode* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}
