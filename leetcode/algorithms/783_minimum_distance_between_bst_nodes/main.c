#include <limits.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderTraversal(struct TreeNode* node, int* vals, int* index) {
    if (!node) {
        return;
    }

    inorderTraversal(node->left, vals, index);
    vals[++(*index)] = node->val;
    inorderTraversal(node->right, vals, index);
}

int minDiffInBST(struct TreeNode* root) {
    int vals[100];
    int index = -1;

    inorderTraversal(root, vals, &index);

    int min = 10e5;

    for (int i = 0; i < index; i++) {
        int diff = vals[i + 1] - vals[i];

        if (diff < min) {
            min = diff;
        }
    }

    return min;
}


// Solution
void inorderHelper(struct TreeNode* node, struct TreeNode** prev_node, int* res) {
    if (!node) {
        return;
    }

    inorderHelper(node->left, prev_node, res);

    if (*prev_node) {
        int diff = node->val - (*prev_node)->val;
        if (diff < *res) {
            *res = diff;
        }
    }
    *prev_node = node;

    inorderHelper(node->right, prev_node, res);
}

int solution(struct TreeNode* root) {
    int res = INT_MAX;
    struct TreeNode* prev_node = (void*)0;
    inorderHelper(root, &prev_node, &res);
    return res;
}
