#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Recursion
 * 
 * Complexities:
 *   N - Size of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
void getVal(struct TreeNode* node, int* array, int* returnSize) {
    if (node) {
        returnArray(node->left, array, returnSize);
        array[(*returnSize)++] = node->val;
        returnArray(node->right, array, returnSize);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;

    getval(root, array, returnSize);

    return array;
}


// Solution
/**
 * Solution 1
 * 
 * Recursion
 *
 * Complexities:
 *   N - Size of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(struct TreeNode* root, int* arr, int* idx) {
    if (root == NULL) {
        return;
    }

    inorder(root->left, arr, idx);
    arr[(*idx)++] = root->val;
    inorder(root->right, arr, idx);
}

int* solution1(struct TreeNode* root, int* returnSize) {
    int count = countNodes(root);

    int* result = (int*)malloc(sizeof(int) * count);

    int idx = 0;
    inorder(root, result, &idx);

    *returnSize = count;
    return result;
}

/**
 * Solution 2
 * 
 * Iteration
 *
 * Complexities:
 *   N - Size of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
#define MAX_NODES 100

int* solution2(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * MAX_NODES);
    *returnSize = 0;

    struct TreeNode* stack[MAX_NODES];
    int top = -1;

    struct TreeNode* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        
        result[(*returnSize)++] = curr->val;

        curr = curr->right;
    }

    return result;
}
