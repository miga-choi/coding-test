#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class DiameterOfBinaryTree {
public:
    int returnDepth(TreeNode* root, int& n) {
        if (!root) {
            return 0;
        }

        int left = returnDepth(root->left, n);
        int right = returnDepth(root->right, n);

        if (left + right > n) {
            n = left + right;
        }

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int n = 0;
        returnDepth(root, n);
        return n;
    }

    // Solution
    int rec(TreeNode* root, int& d) {
        if (root == NULL) {
            return 0;
        }
        int ld = rec(root->left, d);
        int rd = rec(root->right, d);
        d = max(d, ld + rd);
        return max(ld, rd) + 1;
    }

    int solution(TreeNode* root) {
        int d = 0;
        rec(root, d);
        return d;
    }
};
