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
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q) {
        return true;
    }

    if (!p || !q || p->val != q->val) {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


// Solution
/**
 * Recursion: DFS
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 */
bool solution(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }

    if (p == NULL || q == NULL || p->val != q->val) {
        return false;
    }

    return solution(p->left, q->left) && solution(p->right, q->right);
}
