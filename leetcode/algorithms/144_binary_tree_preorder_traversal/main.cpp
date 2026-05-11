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
    /**
     * Recursion
     *
     * Complexities:
     *   N - Number of nodes in `root`
     *   H - Height of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
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
    /**
     * Solution 1
     *
     * Recursion
     *
     * Complexities:
     *   N - Number of nodes in `root`
     *   H - Height of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    void preorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        result.push_back(node->val);
        preorder(node->left, result);
        preorder(node->right, result);
    }

    vector<int> solution1(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

    /**
     * Solution 2
     *
     * Iteration
     *
     * Complexities:
     *   N - Number of nodes in `root`
     *   H - Height of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    vector<int> solution2(TreeNode* root) {
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            
            result.push_back(curr->val);

            if (curr->right != nullptr) {
                st.push(curr->right);
            }
            
            if (curr->left != nullptr) {
                st.push(curr->left);
            }
        }

        return result;
    }
};
