#include <stddef.h> // NULL

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Recursion (DFS)
 * 
 * Complexities:
 *   N - The Numbder of Nodes in `root`
 *   H - The Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
int sumOfLeftLeaves1(struct TreeNode* root) {
    int sum = 0;

    if (root) {
        if (root->left) {
            if (!root->left->left && !root->left->right) {
                sum += root->left->val;
            }
        }

        sum += sumOfLeftLeaves1(root->left) + sumOfLeftLeaves1(root->right);
    }

    return sum;
}

/**
 * Recursion (DFS) with Flag
 * 
 * Complexities:
 *   N - The Numbder of Nodes in `root`
 *   H - The Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
int addLeftVal(struct TreeNode* root, int isLeft) {
    int sum = 0;

    if (root) {
        if (!root->left && !root->right && isLeft) {
            sum += root->val;
        } else {
            sum += addLeftVal(root->left, 1) + addLeftVal(root->right, 0);
        }
    }

    return sum;
}

int sumOfLeftLeaves2(struct TreeNode* root) {
    return addLeftVal(root->left, 1) + addLeftVal(root->right, 0);
}


// Solution
/**
 * Solution 1
 * 
 * Recursion (DFS)
 * 
 * Complexities:
 *   N - The Numbder of Nodes in `root`
 *   H - The Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
int solution1(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;
    struct TreeNode* L = root->left;

    if (L != NULL && L->left == NULL && L->right == NULL) {
        sum += L->val;
    } else {
        sum += solution1(L);
    }

    return sum + solution1(root->right);
}

/**
 * Solution 2
 * 
 * Recursion (DFS) with Flag
 * 
 * Complexities:
 *   N - The Numbder of Nodes in `root`
 *   H - The Height of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(H)
 */
static int dfs(struct TreeNode* node, bool isLeft) {
    if (node == NULL) {
        return 0;
    }

    if (node->left == NULL && node->right == NULL) {
        return isLeft ? node->val : 0;
    }

    return dfs(node->left, true) + dfs(node->right, false);
}

int solution2(struct TreeNode* root) {
    return dfs(root, false);
}

/**
 * Solution 3
 * 
 * Iteration with Stack
 * 
 * Complexities:
 *   N - The Numbder of Nodes in `root`
 *   W - The Width of `root`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(W)
 */
int solution3(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    struct TreeNode* stack[1000];
    int top = 0, sum = 0;
    stack[top++] = root;

    while (top > 0) {
        struct TreeNode* node = stack[--top];
        struct TreeNode* L = node->left;

        if (L != NULL) {
            if (L->left == NULL && L->right == NULL) {
                sum += L->val;
            } else {
                stack[top++] = L;
            }
        }

        if (node->right != NULL) {
            stack[top++] = node->right;
        }
    }

    return sum;
}
