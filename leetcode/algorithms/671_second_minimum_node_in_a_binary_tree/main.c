#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void findMinimumValues(struct TreeNode* node, long* smallest, long* secondSmallest) {
    if (node) {
        findMinimumValues(node->left, smallest, secondSmallest);
        findMinimumValues(node->right, smallest, secondSmallest);
        if (node->val < *smallest) {
            *secondSmallest = *smallest;
            *smallest = node->val;
        } else if (node->val != *smallest && node->val < *secondSmallest) {
            *secondSmallest = node->val;
        }
    }
}

int findSecondMinimumValue(struct TreeNode* root) {
    long smallest = LONG_MAX, secondSmallest = LONG_MAX;
    findMinimumValues(root, &smallest, &secondSmallest);
    return secondSmallest;
}

// Solution
int minval(struct TreeNode* p, int first) {
    if (!p) {
        return -1;
    }
    if (p->val != first) {
        return p->val;
    }
    int left = minval(p->left, first), right = minval(p->right, first);

    // If all nodes of a subtree = root->val, there is no second minimum value, return -1.
    if (left == -1) {
        return right;
    }
    if (right == -1) {
        return left;
    }
    return left < right ? left : right;
}

int solution(struct TreeNode* root) {
    if (!root) {
        return -1;
    }
    int ans = minval(root, root->val);
    return ans;
}
