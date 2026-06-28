#include <algorithm> // std::swap
#include <queue>     // std::queue
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class InvertBinaryTree {
public:
    /**
     * Recursiont: DFS
     *
     * Complexities:
     *   N - The Number of nodes in `root`
     *   H - THe Height of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);

        return root;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Recursiont: DFS
     * 
     * Complexities:
     *   N - The Number of nodes in `root`
     *   H - THe Height of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    TreeNode* solution1(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        swap(root->left, root->right);

        solution1(root->left);
        solution1(root->right);

        return root;
    }

    /**
     * Solution 2
     * 
     * Iteration: BFS (Queue)
     * 
     * Complexities:
     *   N - The Number of nodes in `root`
     *   W - THe Width of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(W)
     */
    TreeNode* solution2(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            swap(curr->left, curr->right);

            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }

        return root;
    }
};
