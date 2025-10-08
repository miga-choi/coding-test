#include <algorithm>
#include <queue>
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
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
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
     * Recursiont: DFS
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
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
     * Iteration: BFS (Queue)
     * - Time Complexity: O(N)
     * - Space Complexity: O(W)
     */
    TreeNode* solution1(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            swap(current->left, current->right);

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
        
        return root;
    }
};
