#include <stack>
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

class BinaryTreePreorderTraversal {
public:
    void addVal(TreeNode* node, vector<int>& result) {
        if (node != nullptr) {
            result.push_back(node->val);
            addVal(node->left, result);
            addVal(node->right, result);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        addVal(root, result);
        return result;
    }


    // Solution
    // Solution 1: Iterative solution using stack
    vector<int> solution1(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        while (root || !todo.empty()) {
            if (root) {
                nodes.push_back(root->val);
                if (root->right) {
                    todo.push(root->right);
                }
                root = root->left;
            } else {
                root = todo.top();
                todo.pop();
            }
        }
        return nodes;
    }

    // Solution 2: Recursive solution
    void preorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        nodes.push_back(root->val);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }

    vector<int> solution2(TreeNode* root) {
        vector<int> nodes;
        preorder(root, nodes);
        return nodes;
    }

    // Solution 3: Morris traversal
    vector<int> solution3(TreeNode* root) {
        vector<int> nodes;
        while (root) {
            if (root->left) {
                TreeNode* pre = root->left;
                while (pre->right && pre->right != root) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    pre->right = root;
                    nodes.push_back(root->val);
                    root = root->left;
                } else {
                    pre->right = NULL;
                    root = root->right;
                }
            } else {
                nodes.push_back(root->val);
                root = root->right;
            }
        }
        return nodes;
    }
};
