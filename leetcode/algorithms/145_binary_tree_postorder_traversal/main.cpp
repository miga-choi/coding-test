#include <vector>
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

class BinaryTreePostorderTraversal
{
public:
    void addVal(TreeNode *node, vector<int> &result)
    {
        if (node != nullptr)
        {
            addVal(node->left, result);
            addVal(node->right, result);
            result.push_back(node->val);
        }
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        addVal(root, result);
        return result;
    }

    // Best Solution 1: Iterative solution using stack
    vector<int> bestSolution1(TreeNode *root)
    {
        vector<int> nodes;
        stack<TreeNode *> todo;
        TreeNode *last = NULL;
        while (root || !todo.empty())
        {
            if (root)
            {
                todo.push(root);
                root = root->left;
            }
            else
            {
                TreeNode *node = todo.top();
                if (node->right && last != node->right)
                {
                    root = node->right;
                }
                else
                {
                    nodes.push_back(node->val);
                    last = node;
                    todo.pop();
                }
            }
        }
        return nodes;
    }

    // Best Solution 2: Recursive solution
    vector<int> bestSolution2(TreeNode *root)
    {
        vector<int> nodes;
        postorder(root, nodes);
        return nodes;
    }

    void postorder(TreeNode *root, vector<int> &nodes)
    {
        if (!root)
        {
            return;
        }
        postorder(root->left, nodes);
        postorder(root->right, nodes);
        nodes.push_back(root->val);
    }

    // Best Solution 3: Morris traversal
    vector<int> bestSolution3(TreeNode *root)
    {
        vector<int> nodes;
        TreeNode *dummy = new TreeNode(0);
        dummy->left = root;
        TreeNode *cur = dummy;
        while (cur)
        {
            if (cur->left)
            {
                TreeNode *pre = cur->left;
                while (pre->right && (pre->right != cur))
                {
                    pre = pre->right;
                }
                if (!(pre->right))
                {
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    reverseAddNodes(cur->left, pre, nodes);
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
            else
            {
                cur = cur->right;
            }
        }
        return nodes;
    }

    void reverseNodes(TreeNode *start, TreeNode *end)
    {
        if (start == end)
        {
            return;
        }
        TreeNode *x = start;
        TreeNode *y = start->right;
        TreeNode *z;
        while (x != end)
        {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
    }

    void reverseAddNodes(TreeNode *start, TreeNode *end, vector<int> &nodes)
    {
        reverseNodes(start, end);
        TreeNode *node = end;
        while (true)
        {
            nodes.push_back(node->val);
            if (node == start)
            {
                break;
            }
            node = node->right;
        }
        reverseNodes(end, start);
    }
};
