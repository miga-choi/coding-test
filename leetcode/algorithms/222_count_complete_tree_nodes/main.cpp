struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CountCompleteTreeNodes
{
public:
    int countNodes(TreeNode *root)
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
    int bestSolution(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int hl = 0, hr = 0;

        TreeNode *l = root, *r = root;

        while (l)
        {
            hl++;
            l = l->left;
        }

        while (r)
        {
            hr++;
            r = r->right;
        }

        if (hl == hr)
        {
            return pow(2, hl) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
