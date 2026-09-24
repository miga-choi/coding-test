#include <stack> // std::stack
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class SumOfLeftLeaves {
public:
    /**
     * Recursion
     *
     * Complexities:
     *   N - The Numbder of Nodes in `node`
     *   H - The Height of `node`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    int sumOfLeftLeaves1(TreeNode* root) {
        int sum = 0;

        if (root) {
            if (root->left) {
                if (!root->left->left && !root->left->right) {
                    sum += root->left->val;
                }
            }

            sum += sumOfLeftLeaves1(root->left) + sumOfLeftLeaves1(root->right);
        }

        return sum;
    }

    /**
     * Recursion with Flag
     *
     * Complexities:
     *   N - The Numbder of Nodes in `node`
     *   H - The Height of `node`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    int addLeftVal(TreeNode* root, int isLeft) {
        int sum = 0;

        if (root) {
            if (isLeft && !root->left && !root->right) {
                sum += root->val;
            }

            sum += addLeftVal(root->left, 1) + addLeftVal(root->right, 0);
        }

        return sum;
    }

    int sumOfLeftLeaves2(TreeNode* root) {
        return addLeftVal(root->left, 1) + addLeftVal(root->right, 0);
    }


    // Solution
    /**
     * Solution 1
     * 
     * Recursion
     *
     * Complexities:
     *   N - The Numbder of Nodes in `node`
     *   H - The Height of `node`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    static bool isLeaf(const TreeNode* n) {
        return n && !n->left && !n->right;
    }

    int solution1(TreeNode* root, bool isleft = false) {
        if (!root) {
            return 0;
        }

        int sum = isLeaf(root->left) ? root->left->val : solution1(root->left);

        return sum + solution1(root->right);
    }

    /**
     * Solution 2
     * 
     * Recursion
     *
     * Complexities:
     *   N - The Numbder of Nodes in `node`
     *   H - The Height of `node`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(H)
     */
    int dfs(TreeNode* node, bool isLeft) {
        if (!node) {
            return 0;
        }

        if (!node->left && !node->right) {
            return isLeft ? node->val : 0;
        }

        return dfs(node->left, true) + dfs(node->right, false);
    }

    int solution2(TreeNode* root) {
        return dfs(root, false);
    }

    /**
     * Solution 3
     *
     * Iteration with Stack
     *
     * Complexities:
     *   N - The Numbder of Nodes in `node`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    int solution3(TreeNode* root) {
        if (!root) {
            return 0;
        }

        stack<TreeNode*> st;
        st.push(root);
        int sum = 0;

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if (TreeNode* L = node->left) {
                if (!L->left && !L->right) {
                    sum += L->val;
                } else {
                    st.push(L);
                }
            }

            if (node->right) {
                st.push(node->right);
            }
        }

        return sum;
    }
};
