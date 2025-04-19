#include <queue>
#include <stack>
#include <string>

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
    // Solution 1: Recursive (DFS) Preorder traversal
    bool solution1(TreeNode* p, TreeNode* q) {
        // Base case: If both trees are empty, they are identical.
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // If one of the trees is empty and the other is not, they are not identical.
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Compare the values of the current nodes.
        if (p->val != q->val) {
            return false;
        }

        // Recursively check the left and right subtrees.
        return solution1(p->left, q->left) && solution1(p->right, q->right);
    }

    // Solution 2: Level-order traversal using Queues
    bool solution2(TreeNode* p, TreeNode* q) {
        // Create queues for both trees.
        std::queue<TreeNode*> queue1;
        std::queue<TreeNode*> queue2;

        // Start by adding the root nodes of both trees to their respective queues.
        queue1.push(p);
        queue2.push(q);

        while (!queue1.empty() && !queue2.empty()) {
            TreeNode* node1 = queue1.front();
            TreeNode* node2 = queue2.front();
            queue1.pop();
            queue2.pop();

            // If the values of the current nodes are not equal, the trees are not identical.
            if (node1 == NULL && node2 == NULL) {
                continue;
            }
            if (node1 == NULL || node2 == NULL || node1->val != node2->val) {
                return false;
            }

            // Add the left and right children of both nodes to their respective queues.
            queue1.push(node1->left);
            queue1.push(node1->right);
            queue2.push(node2->left);
            queue2.push(node2->right);
        }

        // If both queues are empty, the trees are identical.
        return queue1.empty() && queue2.empty();
    }

    // Solution 3: Level-order traversal using Stack
    bool solution3(TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> stack1, stack2;

        // Push the root nodes of both trees onto their respective stacks.
        stack1.push(p);
        stack2.push(q);

        while (!stack1.empty() && !stack2.empty()) {
            TreeNode* node1 = stack1.top();
            stack1.pop();
            TreeNode* node2 = stack2.top();
            stack2.pop();

            // Compare the values of the current nodes.
            if (!node1 && !node2) {
                // Both nodes are null, so they match.
                continue;
            }
            else if (!node1 || !node2 || node1->val != node2->val) {
                // Nodes are not identical, return false.
                return false;
            }

            // Push the left children onto the stacks.
            stack1.push(node1->left);
            stack2.push(node2->left);

            // Push the right children onto the stacks.
            stack1.push(node1->right);
            stack2.push(node2->right);
        }

        // If both stacks are empty, and no mismatches have been found, the trees are identical.
        return stack1.empty() && stack2.empty();
    }

    // Solution 4: Tree Hashing
    bool solution4(TreeNode* p, TreeNode* q) {
        std::string hash1 = solution4_computeTreeHash(p);
        std::string hash2 = solution4_computeTreeHash(q);
        return hash1 == hash2;
    }

    std::string solution4_computeTreeHash(TreeNode* node) {
        if (node == nullptr) {
            return "null";
        }
        std::string leftHash = solution4_computeTreeHash(node->left);
        std::string rightHash = solution4_computeTreeHash(node->right);
        return "(" + std::to_string(node->val) + leftHash + rightHash + ")";
    }
};
