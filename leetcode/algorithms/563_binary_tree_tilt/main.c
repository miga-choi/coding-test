#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int sumVal(struct TreeNode* node, int* total) {
    if (!node) {
        return 0;
    }

    int left = sumVal(node->left, total);

    int right = sumVal(node->right, total);

    *total += abs(left - right);

    return left + right + node->val;
}

int findTilt(struct TreeNode* root) {
    int total = 0;
    sumVal(root, &total);
    return total;
}

// Solution: Post-Order DFS Traversal
int totalTilt = 0;

int valueSum(struct TreeNode* node) {
    if (!node) {
        return 0;
    }

    int leftSum = valueSum(node->left);
    int rightSum = valueSum(node->right);
    int tilt = abs(leftSum - rightSum);
    totalTilt += tilt;

    // return the sum of values starting from this node.
    return node->val + leftSum + rightSum;
}

int solution(struct TreeNode* root) {
    totalTilt = 0;
    valueSum(root);
    return totalTilt;
}
