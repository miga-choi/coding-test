#include <algorithm>
#include <cstdlib>
using namespace std;

class BalancedBinaryTree {
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
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    int getMaxDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left_depth = getMaxDepth(node->left);
        if (left_depth < 0) {
            return -1;
        }

        int right_depth = getMaxDepth(node->right);
        if (right_depth < 0) {
            return -1;
        }

        if (abs(left_depth - right_depth) > 1) {
            return -1;
        }

        return max(left_depth, right_depth) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return getMaxDepth(root) != -1;
    }


    // Solution
    /**
     * Recursion: DFS
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    int getHeightAndCheckBalance(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = getHeightAndCheckBalance(node->left);
        if (leftHeight == -1) {
            return -1;
        }

        int rightHeight = getHeightAndCheckBalance(node->right);
        if (rightHeight == -1) {
            return -1;
        }

        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return 1 + max(leftHeight, rightHeight);
    }

    bool solution(TreeNode* root) {
        return getHeightAndCheckBalance(root) != -1;
    }
};
