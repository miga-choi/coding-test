#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class SecondMinimumNodeInABinaryTree {
public:
    int returnSecondMinimumValue(TreeNode* node, int minValue) {
        if (!node) {
            return -1;
        }

        if (node->val > minValue) {
            return node->val;
        }

        int left = returnSecondMinimumValue(node->left, node->val);
        int right = returnSecondMinimumValue(node->right, node->val);

        if (left == -1) {
            return right;
        }
        if (right == -1) {
            return left;
        }

        return std::min(left, right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        return returnSecondMinimumValue(root, root->val);
    }

    // Solution
    int minval(TreeNode* p, int first) {
        if (p == nullptr) {
            return -1;
        }
        if (p->val != first) {
            return p->val;
        }
        int left = minval(p->left, first), right = minval(p->right, first);

        // if all nodes of a subtree = root->val, there is no second minimum value, return -1
        if (left == -1) {
            return right;
        }
        if (right == -1) {
            return left;
        }
        return std::min(left, right);
    }

    int solution(TreeNode* root) {
        if (!root) {
            return -1;
        }
        int ans = minval(root, root->val);
        return ans;
    }
};
