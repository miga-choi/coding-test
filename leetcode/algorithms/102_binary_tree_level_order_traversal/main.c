#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// Solution
/**
 * BFS
 * 
 * Complexities:
 *   N - Size of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
#define MAX_NODES 2001

int** solution(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    if (root == NULL) {
        return NULL;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAX_NODES);
    int front = 0;
    int rear = 0;

    int** result = (int**)malloc(sizeof(int*) * MAX_NODES);

    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX_NODES);

    queue[rear++] = root;

    while (front < rear) {
        int levelCount = rear - front;

        result[*returnSize] = (int*)malloc(sizeof(int) * levelCount);

        (*returnColumnSizes)[*returnSize] = levelCount;

        for (int i = 0; i < levelCount; i++) {
            struct TreeNode* node = queue[front++];

            result[*returnSize][i] = node->val;

            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
        }

        (*returnSize)++;
    }

    free(queue);

    return result;
}
