#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root)
{
    if (root)
    {
        struct TreeNode *tempNode = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tempNode);
    }
    return root;
}

// Best Solution
struct TreeNode *bestSolution(struct TreeNode *root)
{
    // Base case...
    if (root == NULL)
    {
        return root;
    }

    // Call the function recursively for the left subtree...
    invertTree(root->left);

    // Call the function recursively for the right subtree...
    invertTree(root->right);

    // swapping process...
    struct TreeNode *curr = root->left;
    root->left = root->right;
    root->right = curr;

    return root; // Return the root...
}