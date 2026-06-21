#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Complexities:
 *   N - Number of nodes in `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(logᴺ)
 */
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
/**
 * Complexities:
 *   N - Number of nodes in `root`
 *   - Time Complexity: O(log₂ᴺ)
 *   - Space Complexity: O(logᴺ)
 */
int getLeftHeight(struct TreeNode* node) {
    int height = 0;
    while (node != NULL) {
        height++;
        node = node->left;
    }
    return height;
}

int getRightHeight(struct TreeNode* node) {
    int height = 0;
    while (node != NULL) {
        height++;
        node = node->right;
    }
    return height;
}

int solution(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int lh = getLeftHeight(root);
    int rh = getRightHeight(root);

    if (lh == rh) {
        return (1 << lh) - 1;
    }

    return 1 + solution(root->left) + solution(root->right);
}
