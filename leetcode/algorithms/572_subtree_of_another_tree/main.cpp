struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class SubtreeOfAnotherTree {
public:
    bool compareNode(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr || node2 == nullptr) {
            return node1 == nullptr && node2 == nullptr;
        }
        return (node1->val == node2->val) &&
            compareNode(node1->left, node2->left) &&
            compareNode(node1->right, node2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return subRoot == nullptr;
        }
        return compareNode(root, subRoot) || 
            isSubtree(root->left, subRoot) ||
            isSubtree(root->right, subRoot);
    }

    // Solution
    bool equals(struct TreeNode* root, struct TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        } else if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        return (root->val == subRoot->val) &&
               equals(root->right, subRoot->right) &&
               equals(root->left, subRoot->left);
    }

    bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        return root != nullptr &&
               (equals(root, subRoot) || 
                isSubtree(root->left, subRoot) || 
                isSubtree(root->right, subRoot));
    }
};
