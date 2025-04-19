#include <stdlib.h>
#include <algorithm>
using namespace std;

class BalancedBinaryTree {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

public:
    bool isBalanced(TreeNode* root) {
        if (root) {
            int depth = getDepth(root->left) - getDepth(root->right);
            if (depth < 0) {
                depth *= -1;
            }
            if (depth > 1) {
                return false;
            }
            if (!isBalanced(root->left) || !isBalanced(root->right)) {
                return false;
            }
        }
        return true;
    }

    int getDepth(struct TreeNode* root) {
        if (root) {
            int left = getDepth(root->left);
            int right = getDepth(root->right);
            return (left > right ? left : right) + 1;
        }
        return 0;
    }

    // Solution
    bool solution(TreeNode* root) {
        // If the tree is empty, we can say it’s balanced...
        if (root == NULL) {
            return true;
        }
        // Height Function will return -1, when it’s an unbalanced tree...
        if (Height(root) == -1) {
            return false;
        }
        return true;
    }

    // Create a function to return the “height” of a current subtree using recursion...
    int Height(TreeNode* root) {
        // Base case...
        if (root == NULL) {
            return 0;
        }
        // Height of left subtree...
        int leftHeight = Height(root->left);
        // Height of height subtree...
        int rightHight = Height(root->right);
        // In case of left subtree or right subtree unbalanced or their heights differ by more than ‘1’, return -1...
        if (leftHeight == -1 || rightHight == -1 || abs(leftHeight - rightHight) > 1) {
            return -1;
        }
        // Otherwise, return the height of this subtree as max(leftHeight, rightHight) + 1...
        return max(leftHeight, rightHight) + 1;
    }
};
