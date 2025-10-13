#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Recursion: DFS (Bottom-up)
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 */
#define MAX(a, b) (a > b ? a : b)

int maxDiameter(int* max_diameter, struct TreeNode* node) {
    if (!node) {
        return 0;
    }

    int left_diameter = maxDiameter(max_diameter, node->left);
    int right_diameter = maxDiameter(max_diameter, node->right);

    if (left_diameter + right_diameter > *max_diameter) {
        *max_diameter = left_diameter + right_diameter;
    }

    return MAX(left_diameter, right_diameter) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int max_diameter = 0;

    maxDiameter(&max_diameter, root);

    return max_diameter;
}


// Solution
/**
 * Recursion: DFS (Bottom-up)
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 */
int max(int a, int b) {
    return (a > b) ? a : b;
}

int depth_and_update_diameter(struct TreeNode* node, int* max_diameter) {
    if (node == NULL) {
        return 0;
    }

    int leftDepth = depth_and_update_diameter(node->left, max_diameter);
    int rightDepth = depth_and_update_diameter(node->right, max_diameter);

    *max_diameter = max(*max_diameter, leftDepth + rightDepth);

    return 1 + max(leftDepth, rightDepth);
}

int solution(struct TreeNode* root) {
    int max_diameter = 0;
    depth_and_update_diameter(root, &max_diameter);
    return max_diameter;
}
