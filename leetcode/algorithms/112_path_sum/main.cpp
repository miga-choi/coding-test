#include <stdlib.h>
#include <stack>
using namespace std;

class PathSum {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        targetSum -= root->val;

        if (!root->left && !root->right) {
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }


    // Solution
    // Solution 1: Recursive
    bool solution1(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        if (root->val == targetSum && root->left == NULL && root->right == NULL) {
            return true;
        }
        return solution1(root->left, targetSum - root->val) || solution1(root->right, targetSum - root->val);
    }

    // Solution 2: Iterative
    bool solution2(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        stack<pair<TreeNode*, int>> stack;
        stack.push({root, root->val});
        while (!stack.empty()) {
            TreeNode* current = stack.top().first;
            int total_sum = stack.top().second;
            stack.pop();
            if (current->right) {
                stack.push({current->right, total_sum + current->right->val});
            }

            if (current->left) {
                stack.push({current->left, total_sum + current->left->val});
            }

            // if its a leaf and total sum is found
            if (!current->right && !current->left && total_sum == targetSum) {
                return true;
            }
        }
        return false;
    }
};
