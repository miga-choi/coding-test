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
        for (int i = 0; i < node->numChildren; i++) {
            addVal(node->children[i], valArray, size);
        }
        valArray[(*size)++] = node->val;
    }
}

int* postorder(struct Node* root, int* returnSize) {
    int* valArray = (int*)malloc(sizeof(int) * 10000);
    int size = 0;
    addVal(root, valArray, &size);
    *returnSize = size;
    return valArray;
}

// Solution