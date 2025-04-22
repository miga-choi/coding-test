#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int getDepth(struct TreeNode* root) {
    if (root) {
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return (left > right ? left : right) + 1;
    }
    return 0;
}

bool isBalanced(struct TreeNode* root) {
    if (root) {
        int depth = getDepth(root->left) - getDepth(root->right);
        if (depth < 0) {
            depth *= -1;
        }
        if (depth > 1) {
            return false;
        }
        if (!isBalanced(root->left) || !isBalanced(root->right)) {
            return false;
        }
    }
    return true;
}


// Solution
int solution_maxdepth(struct TreeNode* root, int depth) {
    if (depth < 0 || root == NULL) {
        return depth; // return depth if it reaches the end or it's already not balanced
    }
    int left = solution_maxdepth(root->left, depth + 1);
    int right = solution_maxdepth(root->right, depth + 1);
    depth = (left > right) ? left : right; // choose max depth
    if (abs(left - right) > 1) {
        depth *= (-1); // not balanced, convert to negative value
    }
    return depth;
}

bool solution(struct TreeNode* root) {
    return solution_maxdepth(root, 0) >= 0; // negative: not balanced, positive: balanced
}
