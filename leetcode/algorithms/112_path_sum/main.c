#include <stdbool.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int targetSum)
{
    if (!root)
    {
        return false;
    }

    targetSum -= root->val;

    if (!root->left && !root->right)
    {
        return targetSum == 0;
    }

    if (!root->left)
    {
        return hasPathSum(root->right, targetSum);
    }

    if (!root->right)
    {
        return hasPathSum(root->left, targetSum);
    }

    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}


// Best Solution
// Best Solution 1:
bool bestSolution1(struct TreeNode *root, int targetSum)
{
    // If the tree is empty i.e. root is NULL, return false...
    if (root == NULL)
    {
        return false;
    }

    // If there is only a single root node and the value of root node is equal to the targetSum...
    if (root->val == targetSum && (root->left == NULL && root->right == NULL))
    {
        return true;
    }

    // Call the same function recursively for left and right subtree...
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

// Best Solution 2:
bool bestSolution2(struct TreeNode *root, int targetSum)
{
    if (!root)
    {
        return false;
    }

    if (!root->right && !root->left)
    {
        return targetSum == root->val;
    }

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}
