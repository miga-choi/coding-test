#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool compareNode(struct TreeNode* node1, struct TreeNode* node2) {
    if (!node1 || !node2) {
        return !node1 && !node2;
    }
    return node1->val == node2->val && 
           compareNode(node1->left, node2->left) &&
           compareNode(node1->right, node2->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (!root) {
        return !subRoot;
    }
    return compareNode(root, subRoot) || 
           isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}

// Solution
bool equals(struct TreeNode* root, struct TreeNode* subRoot) {
    if (!root && !subRoot) {
        return true;
    } else if (!root || !subRoot) {
        return false;
    }
    return (root->val == subRoot->val) && equals(root->right, subRoot->right) && equals(root->left, subRoot->left);
}

bool solution(struct TreeNode* root, struct TreeNode* subRoot) {
    if (!root && !subRoot) {
        return true;
    }
    return root && (equals(root, subRoot) || solution(root->left, subRoot) || solution(root->right, subRoot));
}
