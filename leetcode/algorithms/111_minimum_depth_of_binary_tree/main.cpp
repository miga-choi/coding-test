#include <algorithm>
#include <queue>
using namespace std;

class MinimumDepthOfBinaryTree {
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
     *   - Space Complexity: O(H)
     */
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_depth = minDepth(root->left);
        int right_depth = minDepth(root->right);

        if (left_depth == 0 || right_depth == 0) {
            return max(left_depth, right_depth) + 1;
        }

        return min(left_depth, right_depth) + 1;
    }


    // Solution
    /**
     * Solution 1
     *
     * Iteration: BFS (Queue)
     *
     * Complexities:
     *   N - Number of nodes in `root`
     *   W - Width of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(W)
     */
    int solution1(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left == nullptr && curr->right == nullptr) {
                    return depth;
                }

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            depth++;
        }

        return depth;
    }

    /**
     * Solution 2
     * 
     * Recursion: DFS
     * 
     * Complexities:
     *   N - Number of nodes in `root`
     *   H - Height of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    int solution2(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        if (root->left == nullptr) {
            return 1 + solution2(root->right);
        }
        if (root->right == nullptr) {
            return 1 + solution2(root->left);
        }

        return 1 + min(solution2(root->left), solution2(root->right));
    }
};
