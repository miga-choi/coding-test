#include <stdlib.h>;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* convertToBST(int* nums, int left, int right) {
    if (right < left) {
        return (void*)0;
    }

    int mid = (left + right) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    node->val = nums[mid];
    node->left = convertToBST(nums, left, mid - 1);
    node->right = convertToBST(nums, mid + 1, right);

    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return (void*)0;
    }

    return convertToBST(nums, 0, numsSize - 1);
}


// Solution
// Solution 1:
struct TreeNode* solution1_convToBST(int* nums, int beg, int end) {
    if (end < beg) {
        return NULL;
    }
    int mid = (beg + end) / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = solution1_convToBST(nums, beg, mid - 1);
    root->right = solution1_convToBST(nums, mid + 1, end);
    return root;
}

struct TreeNode* solution1(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return NULL;
    } else {
        return solution1_convToBST(nums, 0, numsSize - 1);
    }
}

// Solution 2:
struct TreeNode* solution2(int* nums, int numsSize) {
    if (numsSize == 0) {
        return NULL;
    }
    int midIndex = numsSize >> 1;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = nums[midIndex];
    node->left = solution2(&nums[0], midIndex);
    node->right = solution2(&nums[midIndex + 1], numsSize - midIndex - 1);
    return node;
}
