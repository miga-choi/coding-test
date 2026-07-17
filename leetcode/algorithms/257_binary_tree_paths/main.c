#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * DFS + Backtracking
 * 
 * Complexities:
 *   N - The number of nodes in `root`
 *   H - The height of tree in `root`
 *   - Time Complexity: O(N * H)
 *   - Space Complexity: O(H)
 */
void calculatePath(struct TreeNode* root, char* string, char** stringArray, int* size) {
    if (!root) {
        return;
    }

    char* stringEndPoint = string + strlen(string);
    sprintf(stringEndPoint, "%s%d", strlen(string) == 0 ? "" : "->", root->val);

    if (!root->left && !root->right) {
        stringArray[*size] = calloc(strlen(string) + 1, sizeof(char));
        strcpy(stringArray[*size], string);
        *size += 1;
    } else {
        calculatePath(root->left, string, stringArray, size);
        calculatePath(root->right, string, stringArray, size);
    }

    *stringEndPoint = '\0';
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** stringArray = calloc(100, sizeof(char*));
    int size = 0;
    char buffer[100] = {0};
    calculatePath(root, buffer, stringArray, &size);
    *returnSize = size;
    return stringArray;
}


// Solution
/**
 * DFS + Backtracking
 * 
 * Complexities:
 *   N - The number of nodes in `root`
 *   H - The height of tree in `root`
 *   - Time Complexity: O(N * H)
 *   - Space Complexity: O(H)
 */
void dfs(struct TreeNode* node, int* path, int pathLen, char*** result, int* returnSize, int* capacity) {
    if (node == NULL) {
        return;
    }

    path[pathLen++] = node->val;

    if (node->left == NULL && node->right == NULL) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = (char**)realloc(*result, sizeof(char*) * (*capacity));
        }

        char* pathStr = (char*)malloc(sizeof(char) * 1000);
        int pos = 0;

        for (int i = 0; i < pathLen; i++) {
            if (i > 0) {
                pos += sprintf(pathStr + pos, "->");
            }
            pos += sprintf(pathStr + pos, "%d", path[i]);
        }

        (*result)[(*returnSize)++] = pathStr;
        return;
    }

    if (node->left != NULL) {
        dfs(node->left, path, pathLen, result, returnSize, capacity);
    }
    if (node->right != NULL) {
        dfs(node->right, path, pathLen, result, returnSize, capacity);
    }
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    int capacity = 10;
    char** result = (char**)malloc(sizeof(char*) * capacity);
    
    int path[101];

    dfs(root, path, 0, &result, returnSize, &capacity);

    result = (char**)realloc(result, sizeof(char*) * (*returnSize));

    return result;
}
