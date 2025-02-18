#include <stdlib.h>

struct Node {
    int val;
    int numChildren;
    struct Node** children;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void addVal(struct Node* node, int* valArray, int* size) {
    if (node) {
        valArray[(*size)++] = node->val;
        for (int i = 0; i < node->numChildren; i++) {
            addVal(node->children[i], valArray, size);
        }
    }
}

int* preorder(struct Node* root, int* returnSize) {
    int* valArray = (int*)malloc(sizeof(int) * 10000);
    int size = 0;
    addVal(root, valArray, &size);
    *returnSize = size;
    return valArray;
}

// Solution
void solution(struct Node* root, int* arr, int* returnSize) {
    if (!root) {
        return;
    }

    arr[(*returnSize)++] = root->val;

    for (int i = 0; i < root->numChildren; ++i) {
        solution(root->children[i], arr, returnSize);
    }
}

int* solution(struct Node* root, int* returnSize) {
    int* arr = (int*)calloc(sizeof(int), 10001);
    *returnSize = 0;
    solution(root, arr, returnSize);
    return arr;
}
