#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void getVal(struct TreeNode* node, char* result, int* size) {
    if (!node) {
        return;
    }

    snprintf(result + strlen(result), *size, "%d", node->val);

    if (node->left) {
        result[strlen(result)] = '(';
        getVal(node->left, result, size);
        result[strlen(result)] = ')';
    }

    if (node->right) {
        if (!node->left) {
            result[strlen(result)] = '(';
            result[strlen(result)] = ')';
        }

        result[strlen(result)] = '(';
        getVal(node->right, result, size);
        result[strlen(result)] = ')';
    }
}

char* tree2str(struct TreeNode* root) {
    int size = 100000;
    char* result = (char*)calloc(size, sizeof(char));
    getVal(root, result, &size);
    result[strlen(result)] = '\0';
    return result;
}

// Solution 1
// Variable to store the final string representation of the tree
char ans[100000];

// Helper function to perform preorder traversal of the tree and construct the string
void pre(struct TreeNode* root) {
    if (root == NULL) {
        // Base case: If the node is null, return
        return;
    }

    // Append the current node's value to the string
    sprintf(ans + strlen(ans), "%d", root->val);

    // If the current node has a left child or a right child, include parentheses
    if (root->left != NULL || root->right != NULL) {
        sprintf(ans + strlen(ans), "(");

        // Recursive call to process the left subtree
        pre(root->left);

        sprintf(ans + strlen(ans), ")");
    }

    // If the current node has a right child, include parentheses
    if (root->right != NULL) {
        sprintf(ans + strlen(ans), "(");

        // Recursive call to process the right subtree
        pre(root->right);

        sprintf(ans + strlen(ans), ")");
    }
}

// Main function to convert the binary tree to the required string format
char* solution1(struct TreeNode* root) {
    // Initialize the string
    ans[0] = '\0';

    // Call the helper function to construct the string
    pre(root);

    // Return the final string representation of the tree
    return ans;
}

// Solution 2
void inorder(struct TreeNode* root, char* pRetVal, int* returnSize) {
    if (root == NULL) {
        return;
    }

    snprintf(pRetVal + strlen(pRetVal), (*returnSize), "%d", root->val);

    if (root->left != NULL) {
        pRetVal[strlen(pRetVal)] = '(';
        inorder(root->left, pRetVal, returnSize);
        pRetVal[strlen(pRetVal)] = ')';
    }

    if (root->right != NULL) {
        if (root->left == NULL) {
            pRetVal[strlen(pRetVal)] = '(';
            pRetVal[strlen(pRetVal)] = ')';
        }

        pRetVal[strlen(pRetVal)] = '(';
        inorder(root->right, pRetVal, returnSize);
        pRetVal[strlen(pRetVal)] = ')';
    }
}

char* solution2(struct TreeNode* root) {
    char* pRetVal = NULL;

    /* Constraints
     *  The number of nodes in the tree is in the range [1, 10^4].
     *  -1000 <= Node.val <= 1000
     */
    int returnSize = 1e5;
    pRetVal = (char*)calloc(returnSize, sizeof(char));
    if (pRetVal == NULL) {
        perror("calloc");
        return pRetVal;
    }
    inorder(root, pRetVal, &returnSize);
    pRetVal[strlen(pRetVal)] = '\0';

    return pRetVal;
}
