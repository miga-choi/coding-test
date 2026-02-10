#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BinaryTreeInorderTraversal {
public:
    /**
     * Recursion
     *
     * Complexities:
     *   N - Size of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    void getVal(TreeNode* node, vector<int>& array) {
        if (node != nullptr) {
            getVal(node->left, array);
            array.push_back(node->val);
            getVal(node->right, array);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> array;

        getVal(root, array);

        return array;
    }


    // Solution
    /**
     * Solution 1
     *
     * Recursion
     *
     * Complexities:
     *   N - Size of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }

    vector<int> solution1(TreeNode* root) {
        vector<int> result;

        inorder(root, result);

        return result;
    }

    /**
     * Solution 2
     *
     * Iteration
     *
     * Complexities:
     *   N - Size of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<int> solution2(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            result.push_back(curr->val);

            curr = curr->right;
        }

        return result;
    }
};
