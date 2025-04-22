struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class InvertBinaryTree {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            TreeNode* tempNode = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(tempNode);
        }
        return root;
    }

    // Solution
    TreeNode* solution(TreeNode* root) {
        // Base Case
        if (root == nullptr) {
            return nullptr;
        }

        // Call the left substree
        solution(root->left);

        // Call the right substree
        solution(root->right);

        // Swap the nodes
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Return the root
        return root;
    }
};
