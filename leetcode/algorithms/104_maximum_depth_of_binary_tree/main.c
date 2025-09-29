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
 * Recursion: DFS
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}

int solution(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = solution(root->left);
    int rightDepth = solution(root->right);

    return 1 + max(leftDepth, rightDepth);
}
