#include <stdlib.h>;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Divide-and-conquer
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(logᴺ)
 */
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
/**
 * Divide-and-conquer
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(logᴺ)
 */
 struct TreeNode* buildBST(int* nums, int left, int right) {
    if (left > right) {
        return NULL;
    }

    int mid = left + (right - left) / 2;

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];

    node->left = buildBST(nums, left, mid - 1);
    
    node->right = buildBST(nums, mid + 1, right);

    return node;
}

struct TreeNode* solution(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) {
        return NULL;
    }

    return buildBST(nums, 0, numsSize - 1);
}
