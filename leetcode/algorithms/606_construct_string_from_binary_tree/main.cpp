#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class ConstructStringFromBinaryTree {
public:
    void getVal(TreeNode* node, string& result) {
        if (!node) {
            return;
        }

        result += to_string(node->val);

        if (node->left) {
            result += "(";
            getVal(node->left, result);
            result += ")";
        }

        if (node->right) {
            if (!node->left) {
                result += "()";
            }

            result += "(";
            getVal(node->right, result);
            result += ")";
        }
    }

    string tree2str(TreeNode* root) {
        string result;
        getVal(root, result);
        return result;
    }

    // Solution
    string solution(TreeNode* root) {
        string ans = to_string(root->val);

        // left side check
        if (root->left) {
            ans += "(" + tree2str(root->left) + ")";
        }

        // right side check
        if (root->right) {
            // left side not present, but right side present
            if (!root->left) {
                ans += "()";
            }
            ans += "(" + tree2str(root->right) + ")";
        }

        return ans;
    }
};
