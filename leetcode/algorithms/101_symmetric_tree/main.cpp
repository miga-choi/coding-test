#include <queue>
using namespace std;

class Solution
{
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:
    bool isSymmetric(TreeNode *root)
    {
        return checkNode(root->left, root->right);
    }

    bool checkNode(TreeNode *leftNode, TreeNode *rightNode)
    {
        if (leftNode == nullptr && rightNode == nullptr)
        {
            return true;
        }

        if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val)
        {
            return false;
        }

        return checkNode(leftNode->left, rightNode->right) && checkNode(leftNode->right, rightNode->left);
    }


    // Best Solution
    // Best Solution 1: Recursive
    bool bestSolution1(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        return bestSolution1_isMirror(root->left, root->right);
    }

    bool bestSolution1_isMirror(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
        {
            return true;
        }
        if (!left || !right)
        {
            return false;
        }
        return (left->val == right->val) && bestSolution1_isMirror(left->left, right->right) && bestSolution1_isMirror(left->right, right->left);
    }

    // Best Solution 2: Iterative
    bool bestSolution2(TreeNode *root)
    {
        TreeNode *left, *right;
        if (!root)
        {
            return true;
        }

        queue<TreeNode *> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty())
        {
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right)
            {
                continue;
            }
            if (NULL == left || NULL == right)
            {
                return false;
            }
            if (left->val != right->val)
            {
                return false;
            }
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};
