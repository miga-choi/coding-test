#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if (!left || !right)
    {
        return (left > right ? left : right) + 1;
    }

    return (left > right ? right : left) + 1;
}


// Best Solution
// Best Solution 1:
int bestSolution1(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if (leftDepth > rightDepth)
        {
            return rightDepth + 1;
        }
        else
        {
            return leftDepth + 1;
        }
    }
}

// Best Solution 2: Recursive
int bestSolution2(struct TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    if (!root->left && !root->right)
    {
        return 1;
    }

    if (!root->left)
    {
        return minDepth(root->right) + 1;
    }

    if (!root->right)
    {
        return minDepth(root->left) + 1;
    }

    return minDepth(root->left) > minDepth(root->right) ? minDepth(root->right) + 1 : minDepth(root->left) + 1;
}
