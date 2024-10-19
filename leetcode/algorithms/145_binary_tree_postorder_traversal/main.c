#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void addVal(struct TreeNode *node, int *returnSize, int *result)
{
    if (node != 0)
    {
        addVal(node->left, returnSize, result);
        addVal(node->right, returnSize, result);
        result[*returnSize] = node->val;
        *returnSize = (*returnSize) + 1;
    }
}

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    int *result = (int *)malloc(sizeof(int) * 100);
    addVal(root, returnSize, result);
    return result;
}

// Best Solution
void postOrder(struct TreeNode *root, int *arr, int *returnSize)
{
    if (root)
    {
        postOrder(root->left, arr, returnSize);
        postOrder(root->right, arr, returnSize);
        arr[(*returnSize)++] = root->val;
    }
    return;
}

int *bestSolution(struct TreeNode *root, int *returnSize)
{
    int *arr = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    postOrder(root, arr, returnSize);
    return arr;
    free(arr);
}
