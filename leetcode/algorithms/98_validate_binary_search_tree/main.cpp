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
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
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
     * Recursion: DFS
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    bool isValid(TreeNode* node, long long min_val, long long max_val) {
        if (node == nullptr) {
            return true;
        }

        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }

        return isValid(node->left, min_val, node->val) &&
               isValid(node->right, node->val, max_val);
    }

    bool solution(TreeNode* root) {
        long long min_limit = numeric_limits<long long>::min();
        long long max_limit = numeric_limits<long long>::max();

        return isValid(root, min_limit, max_limit);
    }
};
