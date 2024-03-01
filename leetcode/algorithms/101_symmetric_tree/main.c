#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool checkNode(struct TreeNode *leftNode, struct TreeNode *rightNode)
{
    if (!leftNode && !rightNode)
    {
        return true;
    }

    if (!leftNode || !rightNode || leftNode->val != rightNode->val)
    {
        return false;
    }

    return checkNode(leftNode->left, rightNode->right) && checkNode(leftNode->right, rightNode->left);
}

bool isSymmetric(struct TreeNode *root)
{
    return checkNode(root->left, root->right);
}


// Best Solution
bool bestSolution_isMirror(struct TreeNode *left, struct TreeNode *right)
{
    if (!left && !right)
    {
        return true;
    }
    if (!left || !right)
    {
        return false;
    }
    return (left->val == right->val) && bestSolution_isMirror(left->left, right->right) && bestSolution_isMirror(left->right, right->left);
}

bool bestSolution(struct TreeNode *root)
{
    if (!root)
    {
        return true;
    }
    return bestSolution_isMirror(root->left, root->right);
}
