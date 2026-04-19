#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Recursion - DFS
 * 
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }

    targetSum -= root->val;

    if (!root->left && !root->right) {
        return targetSum == 0;
    }

    if (!root->left) {
        return hasPathSum(root->right, targetSum);
    }

    if (!root->right) {
        return hasPathSum(root->left, targetSum);
    }

    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}


// Solution
/**
 * Recursion - DFS
 * 
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
bool solution(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return (targetSum == root->val);
    }

    int remainingSum = targetSum - root->val;

    return solution(root->left, remainingSum) || solution(root->right, remainingSum);
}
