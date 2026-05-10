#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Recursion
 * 
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
void addVal(struct TreeNode* node, int* returnSize, int* result) {
    if (node != 0) {
        result[*returnSize] = node->val;
        *returnSize = (*returnSize) + 1;
        addVal(node->left, returnSize, result);
        addVal(node->right, returnSize, result);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;
    addVal(root, returnSize, result);
    return result;
}


// Solution
/**
 * Solution 1
 * 
 * Recursion
 * 
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
void preorder(struct TreeNode* node, int* result, int* idx) {
    if (node == NULL) {
        return;
    }

    result[*idx] = node->val;
    (*idx)++;

    preorder(node->left, result, idx);

    preorder(node->right, result, idx);
}

int* solution1(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    preorder(root, result, returnSize);

    return result;
}

/**
 * Solution 1
 * 
 * Iteration
 * 
 * Complexities:
 *   N - Number of nodes in `root`
 *   H - Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
int* solution2(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    if (root == NULL) {
        return result;
    }

    struct TreeNode* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* curr = stack[top--];
        
        result[(*returnSize)++] = curr->val;

        if (curr->right != NULL) {
            stack[++top] = curr->right;
        }

        if (curr->left != NULL) {
            stack[++top] = curr->left;
        }
    }

    return result;
}
