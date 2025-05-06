struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (!root) {
        return (void*)0;
    }

    if (root->val == val) {
        return root;
    }

    if (root->left) {
        struct TreeNode* left = searchBST(root->left, val);
        if (left) {
            return left;
        }
    }

    if (root->right) {
        struct TreeNode* right = searchBST(root->right, val);
        if (right) {
            return right;
        }
    }

    return (void*)0;
}


// Solution
// Solution 1: Recursion
struct TreeNode* solution1(struct TreeNode* root, int val) {
    if (!root) {
        return root;
    }
    if (root->val == val) {
        return root;
    } else {
        return val < root->val ? solution1(root->left, val) : solution1(root->right, val);
    }
}

// Solution 2: Iteration
struct TreeNode* solution2(struct TreeNode* root, int val) {
    while (root && root->val != val) {
        root = (root->val > val) ? root->left : root->right;
    }
    return root;
}
