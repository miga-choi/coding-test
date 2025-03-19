#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    double* result = (double*)malloc(sizeof(double) * 10000);
    struct TreeNode* queue[10000];
    int left = 0, right = 0;

    queue[right++] = root;
    while (left < right) {
        int nodeCount = right - left;
        double sum = 0;
        for (int i = 0; i < nodeCount; i++) {
            struct TreeNode* node = queue[left++];
            sum += node->val;
            if (node->left) {
                queue[right++] = node->left;
            }
            if (node->right) {
                queue[right++] = node->right;
            }
        }
        result[(*returnSize)++] = sum / nodeCount;
    }

    return result;
}

// Solution
double* solution(struct TreeNode* root, int* returnSize) {
    double* arr = (double*)malloc(sizeof(double) * 10001);
    int x = 0;
    struct TreeNode* queue[10001];
    int rear = 0, front = 0;
    queue[rear++] = root;
    while (front < rear) {
        int curr = rear - front;
        double ans = 0;
        for (int j = 0; j < curr; ++j) {
            struct TreeNode* temp = queue[front++];
            ans += temp->val;
            if (temp->left) {
                queue[rear++] = temp->left;
            }
            if (temp->right) {
                queue[rear++] = temp->right;
            }
        }
        arr[x++] = ans / curr;
    }
    *returnSize = x;
    return arr;
}
