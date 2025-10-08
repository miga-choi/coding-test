#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Recursiont: DFS
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
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
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 */
struct TreeNode* solution(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    solution(root->left);
    solution(root->right);

    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    return root;
}
