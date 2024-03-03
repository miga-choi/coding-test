#include <algorithm>
#include <queue>
#include <stack>
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
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return left >= right ? left + 1 : right + 1;
    }


    // Best Solution
    // Best Solution 1: Recursive (DFS)
    int bestSolution1(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxLeft, maxRight) + 1;
    }

    // Best Solution 2: Iterative (DFS)
    int bestSolution2(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        stack<pair<TreeNode *, int>> s;
        s.push({root, 1});
        int len = 1;
        while (!s.empty())
        {
            pair<TreeNode *, int> front = s.top();
            s.pop();
            len = max(len, front.second);
            if (front.first->left)
            {
                s.push({front.first->left, front.second + 1});
            }
            if (front.first->right)
            {
                s.push({front.first->right, front.second + 1});
            }
        }
        return len;
    }

    // Best Solution 3: Iterative (BFS)
    int bestSolution3(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;

        while (!q.empty())
        {
            ++depth;
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode *front = q.front();
                q.pop();

                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }
        }
        return depth;
    }
};
