#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class CountCompleteTreeNodes {
public:
    /**
     * DFS
     * 
     * Complexities:
     *   N - Number of nodes in `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(logᴺ)
     */
    int countNodes(TreeNode* root) {
        int count = 0;

        if (root) {
            count++;
            if (root->left) {
                count += countNodes(root->left);
            }
            if (root->right) {
                count += countNodes(root->right);
            }
        }

        return count;
    }


    // Solution
    /**
     * Perfect Binary Tree
     * 
     * Complexities:
     *   N - Number of nodes in `root`
     *   - Time Complexity: O(log₂ᴺ)
     *   - Space Complexity: O(logᴺ)
     */
    int getLeftHeight(TreeNode* node) {
        int height = 0;
        while (node != nullptr) {
            height++;
            node = node->left;
        }
        return height;
    }

    int getRightHeight(TreeNode* node) {
        int height = 0;
        while (node != nullptr) {
            height++;
            node = node->right;
        }
        return height;
    }

    int solution(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);

        if (lh == rh) {
            return (1 << lh) - 1;
        }

        return 1 + solution(root->left) + solution(root->right);
    }
};
