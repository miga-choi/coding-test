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
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
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
     * Recursion: DFS
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    bool solution1(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }

        return solution1(p->left, q->left) && solution1(p->right, q->right);
    }

    /**
     * Solution 2
     * 
     * Iteration: Stack (DFS)
     * - Time Complexity: O(N)
     * - Space Complexity: O(H)
     */
    bool solution2(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);

        while (!s.empty()) {
            TreeNode* node2 = s.top();
            s.pop();
            TreeNode* node1 = s.top();
            s.pop();

            if (!node1 && !node2) {
                continue;
            }

            if (!node1 || !node2 || node1->val != node2->val) {
                return false;
            }

            s.push(node1->right);
            s.push(node2->right);
            s.push(node1->left);
            s.push(node2->left);
        }

        return true;
    }

    /**
     * Solution 3
     * 
     * Iteration: Queue (BFS)
     * - Time Complexity: O(N)
     * - Space Complexity: O(W)
     */
    bool solution3(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queue;
        queue.push(p);
        queue.push(q);

        while (!queue.empty()) {
            TreeNode* node1 = queue.front();
            queue.pop();
            TreeNode* node2 = queue.front();
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
