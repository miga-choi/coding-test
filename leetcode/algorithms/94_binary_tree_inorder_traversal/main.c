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
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
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
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 */
 void inorder_recursive(struct TreeNode* node, int** result, int* size, int* capacity) {
    if (node == NULL) {
        return;
    }

    inorder_recursive(node->left, result, size, capacity);

    if (*size >= *capacity) {
        *capacity *= 2;
        *result = (int*)realloc(*result, sizeof(int) * (*capacity));
    }

    (*result)[(*size)++] = node->val;

    inorder_recursive(node->right, result, size, capacity);
}

int* solution1(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 10;
    int size = 0;
    int* result = (int*)malloc(sizeof(int) * capacity);

    inorder_recursive(root, &result, &size, &capacity);

    *returnSize = size;
    return result;
}

/**
 * Solution 2
 * 
 * Iteration
 * - Time Complexity: O(N)
 * - Space Complexity: O(H)
 */
 #define MAX_STACK_SIZE 1000
struct TreeNode* stack[MAX_STACK_SIZE];
int top = -1;

void push(struct TreeNode* node) { stack[++top] = node; }

struct TreeNode* pop() { return stack[top--]; }

bool is_empty() { return top == -1; }

int* solution2(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    int capacity = 10;
    int* result = (int*)malloc(sizeof(int) * capacity);

    struct TreeNode* current = root;
    top = -1;

    while (current != NULL || !is_empty()) {
        while (current != NULL) {
            push(current);
            current = current->left;
        }

        current = pop();

        if (*returnSize >= capacity) {
            capacity *= 2;
            result = (int*)realloc(result, sizeof(int) * capacity);
        }
        result[(*returnSize)++] = current->val;

        current = current->right;
    }

    return result;
}
