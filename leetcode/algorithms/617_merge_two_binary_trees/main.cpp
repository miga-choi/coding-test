#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class MergeTwoBinaryTrees {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        }

        if (!root2) {
            return root1;
        }

        TreeNode* root(new TreeNode(root1->val + root2->val));
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);

        return root;
    }

    // Solution 1: Using Recursion (DFS Similar) 1
    TreeNode* solution1(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        }
        if (!root2) {
            return root1;
        }

        root1->val += root2->val;
        if (root2->left) {
            root1->left = solution1(root1->left, root2->left);
        }
        if (root2->right) {
            root1->right = solution1(root1->right, root2->right);
        }

        return root1;
    }

    // Solution 2: Using Recursion (DFS Similar) 1
    TreeNode* solution2(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        }
        if (!root1) {
            return root2;
        }
        if (!root2) {
            return root1;
        }

        root1->val += root2->val;
        root1->left = solution2(root1->left, root2->left);
        root1->right = solution2(root1->right, root2->right);

        return root1;
    }

    // Solution 3: Create New Tree 1
    void dfs(TreeNode* root1, TreeNode* root2, TreeNode*& root) {
        if (!root1 && !root2) {
            return;
        } else if (root1 && !root2) {
            TreeNode* node(new TreeNode(root1->val));
            root = node;
            dfs(root1->left, root2, root->left);
            dfs(root1->right, root2, root->right);
        } else if (root2 && !root1) {
            TreeNode* node(new TreeNode(root2->val));
            root = node;
            dfs(root1, root2->left, root->left);
            dfs(root1, root2->right, root->right);
        } else {
            TreeNode* node(new TreeNode(root1->val + root2->val));
            root = node;
            dfs(root1->left, root2->left, root->left);
            dfs(root1->right, root2->right, root->right);
        }
    }

    TreeNode* solution3(TreeNode* root1, TreeNode* root2) {
        TreeNode* root(nullptr);
        dfs(root1, root2, root);
        return root;
    }

    // Solution 4: Create New Tree 2
    TreeNode* solution4(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        }
    
        int val1 = root1 ? root1->val : 0;
        int val2 = root2 ? root2->val : 0;
    
        TreeNode* root = new TreeNode(val1 + val2);
        root->left = solution4(root1 ? root1->left : nullptr, root2 ? root2->left : nullptr);
        root->right = solution4(root1 ? root1->right : nullptr, root2 ? root2->right : nullptr);
    
        return root;
    }

    // Solution 5: Iterative - Using Stack
    TreeNode* solution5(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        }
        if (!root1 || !root2) {
            return root1 ? root1 : root2;
        }

        stack<TreeNode*> stack1, stack2;
        stack1.push(root1);
        stack2.push(root2);

        while (!stack1.empty()) {
            TreeNode* node1(stack1.top());
            TreeNode* node2(stack2.top());
            stack1.pop();
            stack2.pop();

            node1->val += node2->val;

            if (!node1->left && node2->left) {
                node1->left = node2->left;
            } else if (node1->left && node2->left) {
                stack1.push(node1->left);
                stack2.push(node2->left);
            }

            if (!node1->right && node2->right) {
                node1->right = node2->right;
            } else if (node1->right && node2->right) {
                stack1.push(node1->right);
                stack2.push(node2->right);
            }
        }

        return root1;
    }

    // Solution 6: Iterative - Using Stack
    TreeNode* solution6(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        }
        if (!root1 || !root2) {
            return root1 ? root1 : root2;
        }

        queue<TreeNode*> queue1, queue2;
        queue1.push(root1);
        queue2.push(root2);

        while (!queue1.empty() && !queue2.empty()) {
            TreeNode* node1(queue1.front());
            TreeNode* node2(queue2.front());
            queue1.pop();
            queue2.pop();

            node1->val += node2->val;

            if (!node1->left && node2->left) {
                node1->left = node2->left;
            } else if (node1->left && node2->left) {
                queue1.push(node1->left);
                queue2.push(node2->left);
            }

            if (!node1->right && node2->right) {
                node1->right = node2->right;
            } else if (node1->right && node2->right) {
                queue1.push(node1->right);
                queue2.push(node2->right);
            }
        }

        return root1;
    }
};
