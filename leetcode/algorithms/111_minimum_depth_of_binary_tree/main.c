#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Recursion: DFS
 * 
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
int minDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int left_depth = minDepth(root->left);
    int right_depth = minDepth(root->right);

    if (!left_depth || !right_depth) {
        return (left_depth > right_depth ? left_depth : right_depth) + 1;
    }

    return (left_depth < right_depth ? left_depth : right_depth) + 1;
}


// Solution
/**
 * Recursion: DFS
 * 
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
 // 두 수 중 작은 값을 구하는 헬퍼 함수
int min(int a, int b) {
    return (a < b) ? a : b;
}

int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    if (root->left == NULL) {
        return 1 + minDepth(root->right);
    }
    if (root->right == NULL) {
        return 1 + minDepth(root->left);
    }

    return 1 + min(minDepth(root->left), minDepth(root->right));
}
