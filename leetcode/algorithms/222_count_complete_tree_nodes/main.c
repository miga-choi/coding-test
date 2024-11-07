#include <cstddef>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode *root)
{
    int count = 0;
    if (root)
    {
        count++;
        if (root->left)
        {
            count += countNodes(root->left);
        }
        if (root->right)
        {
            count += countNodes(root->right);
        }
    }
    return count;
}

// Best Solution
int bestSolution(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int a = bestSolution(root->left);
    int b = bestSolution(root->right);
    return a + b + 1;
}
