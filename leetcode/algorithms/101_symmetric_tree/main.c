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
 *   N - The number of nodes in `root`
 *   H - The heights of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
bool checkNode(struct TreeNode* leftNode, struct TreeNode* rightNode) {
    if (!leftNode && !rightNode) {
        return true;
    }

    if (!leftNode || !rightNode || leftNode->val != rightNode->val) {
        return false;
    }

    return checkNode(leftNode->left, rightNode->right) && checkNode(leftNode->right, rightNode->left);
}

bool isSymmetric(struct TreeNode *root) {
    return checkNode(root->left, root->right);
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
 bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) {
        return true;
    }
    
    if (t1 == NULL || t2 == NULL) {
        return false;
    }
    
    if (t1->val != t2->val) {
        return false;
    }
    
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool solution(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    
    return isMirror(root->left, root->right);
}

