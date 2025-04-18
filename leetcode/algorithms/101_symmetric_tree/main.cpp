#include <queue>
using namespace std;

class SymmetricTree {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

public:
    bool isSymmetric(TreeNode* root) {
        return checkNode(root->left, root->right);
    }

    bool checkNode(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr && rightNode == nullptr) {
            return true;
        }

        if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val) {
            return false;
        }

        return checkNode(leftNode->left, rightNode->right) && checkNode(leftNode->right, rightNode->left);
    }


    // Solution
    // Solution 1: Recursive
    bool solution1(TreeNode* root) {
        if (!root) {
            return true;
        }
        return solution1_isMirror(root->left, root->right);
    }

    bool solution1_isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        }
        if (!left || !right) {
            return false;
        }
        return (left->val == right->val) && solution1_isMirror(left->left, right->right) && solution1_isMirror(left->right, right->left);
    }

    // Solution 2: Iterative
    bool solution2(TreeNode* root) {
        TreeNode* left;
        TreeNode* right;
        if (!root) {
            return true;
        }

        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()) {
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right) {
                continue;
            }
            if (NULL == left || NULL == right) {
                return false;
            }
            if (left->val != right->val) {
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
