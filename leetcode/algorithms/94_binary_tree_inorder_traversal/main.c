#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *result = malloc(sizeof(int *) * 100);
    *returnSize = 0;
    getVal(root, result, returnSize);
    return result;
}

void getVal(struct TreeNode *node, int *array, int *returnSize)
{
    if (!node)
    {
        return;
    }
    getVal(node->left, array, returnSize);
    array[(*returnSize)++] = node->val;
    getVal(node->right, array, returnSize);
}


// Best Solution
// Best Solution 1: Iterative using stack
int *bestSolution1(struct TreeNode *root, int *returnSize)
{
    int *ans = malloc(100 * sizeof(int));
    *returnSize = 0;
    struct TreeNode **stack = malloc(100 * sizeof(struct TreeNode *));
    int top = 0;
    while (top || root)
    {
        if (root)
        {
            stack[top++] = root;
            root = root->left;
        }
        else
        {
            root = stack[--top];
            ans[(*returnSize)++] = root->val;
            root = root->right;
        }
    }
    free(stack);
    ans = realloc(ans, (*returnSize) * sizeof(int));
    return ans;
}

// Best Solution 2: Recursive
void traverse(struct TreeNode *root, int *arr, int *returnSize)
{
    if (root->left)
    {
        traverse(root->left, arr, returnSize);
    }
    arr[(*returnSize)++] = root->val;
    if (root->right)
    {
        traverse(root->right, arr, returnSize);
    }
}

int *bestSolution2(struct TreeNode *root, int *returnSize)
{
    int *arr = malloc(100 * sizeof(int));
    *returnSize = 0;
    if (root)
    {
        traverse(root, arr, returnSize);
    }
    arr = realloc(arr, (*returnSize) * sizeof(int));
    return arr;
}
