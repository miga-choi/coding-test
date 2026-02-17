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
 *   M - The number of nodes in `p`
 *   N - The number of nodes in `q`
 *   H𝗉 - The heights of `p`
 *   H𝗊 - The heights of `q`
 *   - Time Complexity: O(min(M, N))
 *   - Space Complexity: O(min(H𝗉, H𝗊))
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
 * Recursion - DFS
 * 
 * Complexities:
 *   M - The number of nodes in `p`
 *   N - The number of nodes in `q`
 *   H𝗉 - The heights of `p`
 *   H𝗊 - The heights of `q`
 *   - Time Complexity: O(min(M, N))
 *   - Space Complexity: O(min(H𝗉, H𝗊))
 */
bool solution(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }

    if (p == NULL || q == NULL) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    return solution(p->left, q->left) && solution(p->right, q->right);
}
