#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void calculatePath(struct TreeNode *root, char *string, char **stringArray, int *size) {
    if (!root) {
        return;
    }

    char *stringEndPoint = string + strlen(string);
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

char **binaryTreePaths(struct TreeNode *root, int *returnSize) {
    char **stringArray = calloc(100, sizeof(char *));
    int size = 0;
    char buffer[100] = {0};
    calculatePath(root, buffer, stringArray, &size);
    *returnSize = size;
    return stringArray;
}

// Best Solution
#define SIZE_BUFF 100

int size;
char **ret;

void binaryTreePaths_r(struct TreeNode *root, char *prefix) {
    if (root == NULL)
        return;
    char *p = prefix + strlen(prefix);
    sprintf(p, "%s%d", strlen(prefix) == 0 ? "" : "->", root->val);
    if (root->left == NULL && root->right == NULL) {
        ret[size] = calloc(strlen(prefix) + 1, sizeof(char));
        strcpy(ret[size], prefix);
        size++;
    } else {
        binaryTreePaths_r(root->left, prefix);
        binaryTreePaths_r(root->right, prefix);
    }
    *p = '\0';
}

char **bestSolution(struct TreeNode *root, int *returnSize) {
    char buff[SIZE_BUFF] = {0};
    ret = calloc(SIZE_BUFF, sizeof(char *));
    size = 0;

    binaryTreePaths_r(root, buff);

    *returnSize = size;
    return ret;
}
