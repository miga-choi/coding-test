#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class MinimumAbsoluteDifferenceInBST {
public:
    int getMinimumDifference(TreeNode* root) {
        int min = 100000;
        int val = 100000;
        return getMin(root, min, val);
    }

    int getMin(TreeNode* node, int& min, int& val) {
        if (node) {
            getMin(node->left, min, val);

            int diff = abs(node->val - val);
            if (diff < min) {
                min = diff;
            }
            val = node->val;

            getMin(node->right, min, val);
        }
        return min;
    }

    // Solution 1
    int inorderTraverse(TreeNode* root, int& val, int& min_dif) {
        if (root->left != NULL) {
            inorderTraverse(root->left, val, min_dif);
        }
        if (val >= 0) {
            min_dif = min(min_dif, root->val - val);
        }
        val = root->val;
        if (root->right != NULL) {
            inorderTraverse(root->right, val, min_dif);
        }
        return min_dif;
    }

    int solution1(TreeNode* root) {
        auto min_dif = INT_MAX, val = -1;
        return inorderTraverse(root, val, min_dif);
    }

    // Solution 2
    int min_dif = INT_MAX, val = -1;
    int solution2(TreeNode* root) {
        if (root->left != NULL) {
            solution2(root->left);
        }
        if (val >= 0) {
            min_dif = min(min_dif, root->val - val);
        }
        val = root->val;
        if (root->right != NULL) {
            solution2(root->right);
        }
        return min_dif;
    }
};