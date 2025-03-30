#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void inorder(struct TreeNode* node, int* valArray, int* pointer) {
    if (node) {
        inorder(node->left, valArray, pointer);
        valArray[(*pointer)++] = node->val;
        inorder(node->right, valArray, pointer);
    }
}

bool findTarget(struct TreeNode* root, int k) {
    int* valArray = (int*)malloc(sizeof(int) * 10000);
    int pointer = 0;

    inorder(root, valArray, &pointer);

    int left = 0, right = pointer - 1;
    while (left < right) {
        int sum = valArray[left] + valArray[right];
        if (sum < k) {
            left++;
        } else if (sum > k) {
            right--;
        } else {
            return true;
        }
    }

    return false;
}

// Solution
void solution_inorder(struct TreeNode* root, int* ans, int* returnSize) {
    if (!root) {
        return;
    }
    solution_inorder(root->left, ans, returnSize);
    ans[(*returnSize)++] = root->val;
    solution_inorder(root->right, ans, returnSize);
    return;
}

bool solution(struct TreeNode* root, int k) {
    int* ans = (int*)calloc(sizeof(int), 10001);
    int x = 0;
    solution_inorder(root, ans, &x);
    int s = 0;
    x--;
    while (s < x) {
        int sum = ans[s] + ans[x];
        if (sum == k) {
            return true;
        } else if (sum > k) {
            x--;
        } else {
            s++;
        }
    }
    return false;
}
