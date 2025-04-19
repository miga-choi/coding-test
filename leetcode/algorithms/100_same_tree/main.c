#include <stdbool.h>;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

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
bool solution(struct TreeNode* p, struct TreeNode* q) {
    // Base case: If both trees are empty, they are identical.
    if (!p && !q) {
        return true;
    }

    // If one of the trees is empty and the other is not, they are not identical.
    if (!p || !q) {
        return false;
    }

    // Compare the values of the current nodes.
    if (p->val != q->val) {
        return false;
    }

    // Recursively check the left and right subtrees.
    return solution(p->left, q->left) && solution(p->right, q->right);
}
