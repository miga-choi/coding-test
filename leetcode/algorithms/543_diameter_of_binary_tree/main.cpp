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

class DiameterOfBinaryTree {
public:
    /**
     * Recursion: DFS
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    int getMaxDiameter(int& max_diameter,TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left_diameter = getMaxDiameter(max_diameter, node->left);
        int right_diameter = getMaxDiameter(max_diameter, node->right);

        if (left_diameter + right_diameter > max_diameter) {
            max_diameter = left_diameter + right_diameter;
        }

        return max(left_diameter, right_diameter) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;

        getMaxDiameter(max_diameter, root);

        return max_diameter;
    }


    // Solution
    /**
     * Recursion: DFS
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    int max_diameter = 0;

    int depth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);

        max_diameter = max(max_diameter, leftDepth + rightDepth);

        return 1 + max(leftDepth, rightDepth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return max_diameter;
    }
};
