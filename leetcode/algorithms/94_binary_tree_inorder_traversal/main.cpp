#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTreeInorderTraversal
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        getVal(root, &result);
        return result;
    }

    void getVal(TreeNode *node, vector<int> *array)
    {
        if (!node)
        {
            return;
        }

        getVal(node->left, array);
        (*array).push_back(node->val);
        getVal(node->right, array);
    }


    // Best Solution
    // Best Solution 1:
    vector<int> bestSolution1(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        vector<int> left = inorderTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }

    // Best Solution 2: Iterative using stack
    vector<int> bestSolution2(TreeNode *root)
    {
        vector<int> nodes;
        stack<TreeNode *> todo;
        while (root || !todo.empty())
        {
            while (root)
            {
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root->val);
            root = root->right;
        }
        return nodes;
    }

    // Best Solution 3: Recursive
    vector<int> bestSolution3(TreeNode *root)
    {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }

    void inorder(TreeNode *root, vector<int> &nodes)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }

    // Best Solution 4: Morris traversal
    vector<int> bestSolution4(TreeNode *root)
    {
        vector<int> nodes;
        while (root)
        {
            if (root->left)
            {
                TreeNode *pre = root->left;
                while (pre->right && pre->right != root)
                {
                    pre = pre->right;
                }
                if (!pre->right)
                {
                    pre->right = root;
                    root = root->left;
                }
                else
                {
                    pre->right = NULL;
                    nodes.push_back(root->val);
                    root = root->right;
                }
            }
            else
            {
                nodes.push_back(root->val);
                root = root->right;
            }
        }
        return nodes;
    }
};
