#include <queue>
#include <stack>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class SameTree {
public:
    /**
     * Recursion: DFS
     *
     * Complexities:
     *   M - The number of nodes in `p`
     *   N - The number of nodes in `q`
     *   H𝗉 - The heights of `p`
     *   H𝗊 - The heights of `q`
     *   - Time Complexity: O(min(M, N))
     *   - Space Complexity: O(min(H𝗉, H𝗊))
     */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q || p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }


    // Solution
    /**
     * Solution 1
     *
     * Recursion - DFS
     *
     * Complexities:
     *   M - The number of nodes in `p`
     *   N - The number of nodes in `q`
     *   H𝗉 - The heights of `p`
     *   H𝗊 - The heights of `q`
     *   - Time Complexity: O(min(M, N))
     *   - Space Complexity: O(min(H𝗉, H𝗊))
     */
    bool solution1(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return solution1(p->left, q->left) && solution1(p->right, q->right);
    }

    /**
     * Solution 2
     *
     * Iteration - BFS
     *
     * Complexities:
     *   M - The number of nodes in `p`
     *   N - The number of nodes in `q`
     *   H𝗉 - The heights of `p`
     *   H𝗊 - The heights of `q`
     *   - Time Complexity: O(min(M, N))
     *   - Space Complexity: O(min(H𝗉, H𝗊))
     */
    bool solution2(TreeNode* p, TreeNode* q) {
        queue<TreeNode *> queue;
        queue.push(p);
        queue.push(q);

        while (!queue.empty()) {
            TreeNode *node1 = queue.front();
            queue.pop();
            TreeNode *node2 = queue.front();
            queue.pop();

            if (!node1 && !node2) {
                continue;
            }

            if (!node1 || !node2 || node1->val != node2->val) {
                return false;
            }

            queue.push(node1->left);
            queue.push(node2->left);
            queue.push(node1->right);
            queue.push(node2->right);
        }

        return true;
    }
};
