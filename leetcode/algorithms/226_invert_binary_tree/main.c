#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Recursiont: DFS
 * 
 * Complexities:
 *   N - The Number of nodes in `root`
 *   H - THe Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (!root) {
        return (void*)0;
    }

    struct TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}


// Solution
/**
 * Recursiont: DFS
 * 
 * Complexities:
 *   N - The Number of nodes in `root`
 *   H - THe Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
struct TreeNode* solution(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode* leftCloned = solution(root->left);
    struct TreeNode* rightCloned = solution(root->right);

    root->left = rightCloned;
    root->right = leftCloned;

    return root;
}
