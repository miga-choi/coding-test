#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void addVal(struct TreeNode* node, int* returnSize, int* result) {
    if (node != 0) {
        result[*returnSize] = node->val;
        *returnSize = (*returnSize) + 1;
        addVal(node->left, returnSize, result);
        addVal(node->right, returnSize, result);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    addVal(root, returnSize, result);
    return result;
}


// Solution
void preorder(struct TreeNode* root, int* arr, int* returnSize) {
    if (root) {
        arr[(*returnSize)++] = root->val;
        preorder(root->left, arr, returnSize);
        preorder(root->right, arr, returnSize);
    }
    return;
}

int* solution(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    preorder(root, arr, returnSize);
    return arr;
    free(arr);
}
