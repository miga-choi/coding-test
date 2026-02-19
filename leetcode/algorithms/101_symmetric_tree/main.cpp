#include <queue>
using namespace std;

class SymmetricTree {
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
     *   N - The number of nodes in `root`
     *   H - The heights of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    bool isSymmetric(TreeNode* root) {
        return checkNode(root->left, root->right);
    }

    bool checkNode(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr && rightNode == nullptr) {
            return true;
        }

        if (leftNode == nullptr || rightNode == nullptr || leftNode->val != rightNode->val) {
            return false;
        }

        return checkNode(leftNode->left, rightNode->right) && checkNode(leftNode->right, rightNode->left);
    }


    // Solution
    /**
     * Solution 1
     *
     * Recursion - DFS
     *
     * Complexities:
     *   N - The number of nodes in `root`
     *   H - The heights of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    bool solution1(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }

        if (t1 == nullptr || t2 == nullptr) {
            return false;
        }

        if (t1->val != t2->val) {
            return false;
        }

        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }

    /**
     * Solution 2
     *
     * Iteration
     *
     * Complexities:
     *   N - The number of nodes in `root`
     *   H - The heights of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    bool solution2(TreeNode* root) {
        if (!root) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();

            if (!t1 && !t2) {
                continue;
            }

            if (!t1 || !t2 || t1->val != t2->val) {
                return false;
            }

            q.push(t1->left);
            q.push(t2->right);

            q.push(t1->right);
            q.push(t2->left);
        }

        return true;
    }
};
