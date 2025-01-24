#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void order(struct TreeNode* root, int* numArray, int* size) {
    if (!root) {
        return;
    }
    order(root->left, numArray, size);
    numArray[*size] = root->val;
    (*size)++;
    order(root->right, numArray, size);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    int* numArray = (int*)malloc(sizeof(int) * 10000);
    int size = 0;

    order(root, numArray, &size);

    int maxCount = 0;
    int currentCount = 0;
    int currentNum = numArray[0];

    for (int i = 0; i < size; i++) {
        if (currentNum == numArray[i]) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
            currentCount = 1;
            currentNum = numArray[i];
        }
    }

    if (currentCount > maxCount) {
        maxCount = currentCount;
    }

    currentNum = numArray[0];
    currentCount = 0;

    int* result = (int*)malloc(sizeof(int) * size);
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (currentNum == numArray[i]) {
            currentCount++;
        } else {
            if (currentCount == maxCount) {
                result[count] = currentNum;
                count++;
            }
            currentCount = 1;
            currentNum = numArray[i];
        }
    }

    if (currentCount == maxCount) {
        result[count] = currentNum;
        count++;
    }

    *returnSize = count;
    return result;
}

// Solution
void inorder(struct TreeNode* root, int* arr, int* size) {
    if (!root) {
        return;
    }
    inorder(root->left, arr, size);
    arr[(*size)++] = root->val;
    inorder(root->right, arr, size);
}

int* solution(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)calloc(10000, sizeof(int));
    int size = 0;
    inorder(root, arr, &size);

    int* ret = (int*)malloc(sizeof(int) * size);
    int max = 0, idx = 0, len = 0, cur = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] == cur) {
            len++;
        } else {
            if (len > max) {
                idx = 0;
                ret[idx++] = cur;
                max = len;
            } else if (len == max) {
                ret[idx++] = cur;
            }
            cur = arr[i];
            len = 1;
        }
    }

    if (len > max) {
        idx = 0;
        ret[idx++] = cur;
    } else if (len == max) {
        ret[idx++] = cur;
    }

    *returnSize = idx;
    return ret;
}
