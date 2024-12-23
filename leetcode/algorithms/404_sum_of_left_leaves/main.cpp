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

class SumOfLeftLeaves {
public:
    // Solution 1
    int sumOfLeftLeaves1(TreeNode *root) {
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

    // Solution 2
    int addLeftVal(TreeNode *root, int isLeft) {
        int sum = 0;
        if (root) {
            if (isLeft && !root->left && !root->right) {
                sum += root->val;
            }
            sum += addLeftVal(root->left, 1) + addLeftVal(root->right, 0);
        }
        return sum;
    }

    int sumOfLeftLeaves2(TreeNode *root) {
        return addLeftVal(root->left, 1) + addLeftVal(root->right, 0);
    }

    // Best Solution 1: Recursive DFS
    int bestSolution1(TreeNode *root, bool isleft = false) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return isleft ? root->val : 0;
        }
        return bestSolution1(root->left, true) + bestSolution1(root->right, false);
    }

    // Best Solution 2: Iterative DFS
    int bestSolution2(TreeNode *root) {
        stack<pair<TreeNode *, bool>> s;
        s.push({root, false});
        int ans = 0;
        while (s.size()) {
            auto [cur, isLeft] = s.top();
            s.pop();
            if (!cur->left && !cur->right && isLeft) {
                ans += cur->val;
            }
            if (cur->right) {
                s.push({cur->right, false});
            }
            if (cur->left) {
                s.push({cur->left, true});
            }
        }
        return ans;
    }

    // Best Solution 3: BFS
    int bestSolution3(TreeNode *root) {
        queue<pair<TreeNode *, bool>> q;
        q.push({root, false});
        int ans = 0;
        while (q.size()) {
            auto [cur, isLeft] = q.front();
            q.pop();
            if (!cur->left && !cur->right && isLeft) {
                ans += cur->val;
            }
            if (cur->right) {
                q.push({cur->right, false});
            }
            if (cur->left) {
                q.push({cur->left, true});
            }
        }
        return ans;
    }

    // Best Solution 4: Morris Traversal
    int bestSolution4(TreeNode *root) {
        int ans = 0;
        while (root) {
            if (root->left) {
                // find predecessor of root
                auto pre = root->left;

                while (pre->right && pre->right != root) {
                    pre = pre->right;
                }

                // make root as right child of predecessor (temporary link)
                if (!pre->right) {
                    pre->right = root;
                    root = root->left;
                } else {
                    // revert the changes - remove temporary link
                    pre->right = nullptr;

                    // add to sum if node is left child and a leaf
                    if (pre == root->left && !pre->left) {
                        ans += pre->val;
                    }
                    root = root->right;
                }
            } else {
                root = root->right;
            }
        }
        return ans;
    }
};
