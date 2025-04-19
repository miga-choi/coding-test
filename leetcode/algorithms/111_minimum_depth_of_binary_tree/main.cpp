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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (!left || !right) {
            return (left > right ? left : right) + 1;
        }

        return (left > right ? right : left) + 1;
    }


    // Solution
    // Solution 1:
    int solution1(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int L = solution1(root->left), R = solution1(root->right);
        return 1 + (min(L, R) ? min(L, R) : max(L, R));
    }

    // Solution 2:
    int solution2(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int L = solution2(root->left), R = solution2(root->right);
        return 1 + (L && R ? min(L, R) : max(L, R));
    }

    // Solution 3:
    int solution3(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int L = solution3(root->left), R = solution3(root->right);
        return 1 + (!L - !R ? max(L, R) : min(L, R));
    }

    // Solution 4:
    int solution4(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int L = solution4(root->left), R = solution4(root->right);
        return L < R && L || !R ? 1 + L : 1 + R;
    }

    // Solution 5: BFS
    int solution5(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        int i = 0;
        while (!Q.empty()) {
            i++;
            int k = Q.size();
            for (int j = 0; j < k; j++) {
                TreeNode* rt = Q.front();
                if (rt->left) {
                    Q.push(rt->left);
                }
                if (rt->right) {
                    Q.push(rt->right);
                }
                Q.pop();
                if (rt->left == NULL && rt->right == NULL) {
                    return i;
                }
            }
        }
        return -1; // For the compiler thing. The code never runs here.
    }
};
