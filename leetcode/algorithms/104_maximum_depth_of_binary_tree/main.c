#include <stdlib.h> // NULL

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
int maxDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return left >= right ? left + 1 : right + 1;
}


// Solution
/**
 * Recursion - DFS
 * 
 * Complexities:
 *   N - The number of nodes in `root`
 *   H - The heights of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
int solution(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = solution(root->left);
    int rightDepth = solution(root->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
