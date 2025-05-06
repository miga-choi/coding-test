struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class SearchInABinarySearchTree {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root) {
            if (root->val == val) {
                return root;
            }

            if (root->left) {
                TreeNode* left = searchBST(root->left, val);
                if (left) {
                    return left;
                }
            }

            if (root->right) {
                TreeNode* right = searchBST(root->right, val);
                if (right) {
                    return right;
                }
            }
        }

        return nullptr;
    }


    // Solution
    // Solution 1: Recursion
    TreeNode* solution1(TreeNode* root, int val) {
        if (root == nullptr) {
            return root;
        }
        if (root->val == val) {
            return root;
        } else {
            return val < root->val ? solution1(root->left, val) : solution1(root->right, val);
        }
    }

    // Solution 2: Iteration
    TreeNode* solution2(TreeNode* root, int val) {
        while (root != nullptr && root->val != val) {
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
};
