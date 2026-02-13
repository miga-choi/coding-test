#include <numeric>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class ValidateBinarySearchTree {
public:
    /**
     * Recursion: DFS
     * 
     * Complexities:
     *   N - Size of `node`
     *   H - Height of `node`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    bool helper(TreeNode* node, long min_val, long max_val) {
        if (node == nullptr) {
            return true;
        }

        if ((long)node->val <= min_val || (long)node->val >= max_val) {
            return false;
        }

        return helper(node->left, min_val, node->val) &&
               helper(node->right, node->val, max_val);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }


    // Solution
    /**
     * Solution 1
     * 
     * Recursive with Range
     * 
     * Complexities:
     *   N - Size of `node`
     *   H - Height of `node`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        return validate(node->left, minVal, node->val) && validate(node->right, node->val, maxVal);
    }

    bool solution1(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }

    /**
     * Solution 2
     * 
     * Inorder Traversal
     * 
     * Complexities:
     *   N - Size of `node`
     *   H - Height of `node`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    long long prevValue = LLONG_MIN;

    bool solution2(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if (!solution2(root->left)) {
            return false;
        }

        if (root->val <= prevValue) {
            return false;
        }
        prevValue = root->val;

        return solution2(root->right);
    }
};
