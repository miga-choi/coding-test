#include <algorithm> // std::max
#include <queue>     // std::queue
#include <stack>     // std::stack
#include <utility>   // std::pair
using namespace std;

class MaximumDepthOfBinaryTree {
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
     * Recursion - DFS
     *
     * Complexities:
     *   N - The number of nodes in `root`
     *   H - The heights of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return left >= right ? left + 1 : right + 1;
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
    int solution1(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = solution1(root->left);
        int rightDepth = solution1(root->right);

        return 1 + max(leftDepth, rightDepth);
    }

    /**
     * Solution 2
     *
     * Iteration - BFS
     *
     * Complexities:
     *   N - The number of nodes in `root`
     *   H - The heights of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    int solution2(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            depth++;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return depth;
    }
};
