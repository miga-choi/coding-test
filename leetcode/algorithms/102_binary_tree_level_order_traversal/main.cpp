#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BinaryTreeLevelOrderTraversal {
public:
    /**
     * BFS
     * 
     * Complexities:
     *   N - Size of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (!root) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            queue<TreeNode*> tempQ;

            while (!q.empty()) {
                tempQ.push(q.front());
                q.pop();
            }

            vector<int> tempArr;

            while (!tempQ.empty()) {
                TreeNode* node = tempQ.front();
                tempQ.pop();

                if (!node) {
                    break;
                }

                tempArr.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            result.push_back(tempArr);
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * BFS
     * 
     * Complexities:
     *   N - Size of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<vector<int>> solution1(TreeNode* root) {
        vector<vector<int>> result;
        
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                currentLevel.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            result.push_back(currentLevel);
        }

        return result;
    }

    /**
     * Solution 2
     * 
     * DFS
     * 
     * Complexities:
     *   N - Size of `root`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    vector<vector<int>> result;

    void dfs(TreeNode* node, int level) {
        if (!node) return;

        if (result.size() == level) {
            result.push_back(vector<int>());
        }

        result[level].push_back(node->val);

        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }

    vector<vector<int>> solution2(TreeNode* root) {
        dfs(root, 0);
        return result;
    }
};
