#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int minDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if (!left || !right) {
        return (left > right ? left : right) + 1;
    }

    return (left > right ? right : left) + 1;
}


// Solution
// Solution 1
int solution1(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftDepth = solution1(root->left);
        int rightDepth = solution1(root->right);
        if (leftDepth > rightDepth) {
            return rightDepth + 1;
        } else {
            return leftDepth + 1;
        }
    }
}

// Solution 2: Recursive
int solution2(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    if (!root->left && !root->right) {
        return 1;
    }

    if (!root->left) {
        return solution2(root->right) + 1;
    }

    if (!root->right) {
        return solution2(root->left) + 1;
    }

    return solution2(root->left) > solution2(root->right) ? solution2(root->right) + 1 : solution2(root->left) + 1;
}
