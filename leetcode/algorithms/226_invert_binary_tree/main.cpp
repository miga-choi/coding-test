struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class InvertBinaryTree
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root)
        {
            TreeNode *tempNode = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(tempNode);
        }
        return root;
    }

    // Best Solution
    TreeNode *bestSolution(TreeNode *root)
    {
        // Base Case
        if (root == nullptr)
            return nullptr;

        invertTree(root->left);  // Call the left substree
        invertTree(root->right); // Call the right substree

        // Swap the nodes
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root; // Return the root
    }
};