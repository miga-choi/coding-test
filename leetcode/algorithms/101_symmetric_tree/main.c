#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

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
bool solution_isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (!left && !right) {
        return true;
    }
    if (!left || !right) {
        return false;
    }
    return (left->val == right->val) && solution_isMirror(left->left, right->right) && solution_isMirror(left->right, right->left);
}

bool solution(struct TreeNode *root) {
    if (!root) {
        return true;
    }
    return solution_isMirror(root->left, root->right);
}
