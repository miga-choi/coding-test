#include <stack>
#include <utility>
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
    /**
     * Recursion: DFS
     *
     * Complexities:
     *   N - Number of nodes in `root`
     *   H - Height of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
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
    /**
     * Solution 1
     * 
     * Recursion - DFS
     *
     * Complexities:
     *   N - Number of nodes in `root`
     *   H - Height of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    bool solution1(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        int remainingSum = targetSum - root->val;

        return solution1(root->left, remainingSum) || solution1(root->right, remainingSum);
    }

    /**
     * Solution 2
     * 
     * Iteration - DFS with Stack
     *
     * Complexities:
     *   N - Number of nodes in `root`
     *   H - Height of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    bool solution2(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        stack<pair<TreeNode*, int>> st;
        st.push({root, targetSum});

        while (!st.empty()) {
            auto [node, currentSum] = st.top();
            st.pop();

            if (!node->left && !node->right && currentSum == node->val) {
                return true;
            }

            if (node->right) {
                st.push({node->right, currentSum - node->val});
            }
            if (node->left) {
                st.push({node->left, currentSum - node->val});
            }
        }

        return false;
    }
};
