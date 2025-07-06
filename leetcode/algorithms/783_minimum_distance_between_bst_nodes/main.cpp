#include <algorithm>
#include <climits>
#include <cstddef>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class MinimumDistanceBetweenBSTNodes {
public:
    void inorderTraversal(TreeNode* node, vector<int>& vals) {
        if (!node) {
            return;
        }

        inorderTraversal(node->left, vals);
        vals.push_back(node->val);
        inorderTraversal(node->right, vals);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> vals;

        inorderTraversal(root, vals);

        int min = 10e5;

        for (int i = 0; i < vals.size() - 1; i++) {
            int diff = vals[i + 1] - vals[i];
            if (diff < min) {
                min = diff;
            }
        }

        return min;
    }


    // Solution
    int res = INT_MAX, pre = -1;

    int minDiffInBST(TreeNode* root) {
        if (root->left != NULL) {
            minDiffInBST(root->left);
        }

        if (pre >= 0) {
            res = min(res, root->val - pre);
        }

        pre = root->val;

        if (root->right != NULL) {
            minDiffInBST(root->right);
        }

        return res;
    }
};
