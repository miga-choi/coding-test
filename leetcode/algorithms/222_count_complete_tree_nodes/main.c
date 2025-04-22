#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int countNodes(struct TreeNode* root) {
    int count = 0;
    if (root) {
        count++;
        if (root->left) {
            count += countNodes(root->left);
        }
        if (root->right) {
            count += countNodes(root->right);
        }
    }
    return count;
}


// Solution
int solution(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int a = solution(root->left);
    int b = solution(root->right);
    return a + b + 1;
}
