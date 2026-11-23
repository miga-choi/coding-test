#include <stdbool.h> // bool
#include <stdlib.h>  // calloc, malloc, free

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * In-order Traversal to Array + Two-Pass Run Counting
 *
 * Complexities:
 *   n - The Number of Nodes in `root`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(n)
 */
void order1(struct TreeNode* root, int* numArray, int* size) {
    if (!root) {
        return;
    }

    order1(root->left, numArray, size);
    numArray[*size] = root->val;
    (*size)++;
    order1(root->right, numArray, size);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    int* numArray = (int*)malloc(sizeof(int) * 10000);
    int size = 0;

    order1(root, numArray, &size);

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
/**
 * Solution 1
 * 
 * Tree Traversal + Counting Array
 * 
 * Complexities:
 *   n - The Number of Nodes in `root`
 *   V - 2 × 10⁵ + 1
 *   h - The Height of `root`
 *   - Time Complexity: O(n + V)
 *   - Space Complexity: O(V + h)
 */
#define OFFSET 100000
#define RANGE (2 * OFFSET + 1)

static void count(struct TreeNode* node, int* cnt) {
    if (node == NULL) return;
    cnt[node->val + OFFSET]++;
    count(node->left, cnt);
    count(node->right, cnt);
}

int* solution1(struct TreeNode* root, int* returnSize) {
    int* cnt = calloc(RANGE, sizeof(int));
    count(root, cnt);

    int maxCnt = 0, modes = 0;
    for (int v = 0; v < RANGE; v++) {
        if (cnt[v] > maxCnt) {
            maxCnt = cnt[v];
            modes = 1;
        } else if (cnt[v] == maxCnt) {
            modes++;
        }
    }

    int* res = malloc(modes * sizeof(int));
    int k = 0;
    for (int v = 0; v < RANGE; v++) {
        if (cnt[v] == maxCnt) {
            res[k++] = v - OFFSET;
        }
    }

    free(cnt);
    *returnSize = k;
    return res;
}

/**
 * Solution 2
 * 
 * Tree Traversal + Counting Array
 * 
 * Complexities:
 *   n - The Number of Nodes in `root`
 *   h - The Height of `root`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(h)
 */
typedef struct {
    int  prev;
    bool hasPrev;
    int  cur;
    int  max;
    int* res;
    int  size, cap;
} State;

static void visit(State* s, int v) {
    if (s->hasPrev && v == s->prev) {
        s->cur++;
    } else {
        s->cur = 1;
        s->prev = v;
        s->hasPrev = true;
    }

    if (s->cur > s->max) {
        s->max = s->cur;
        s->size = 0;
    }
    if (s->cur == s->max) {
        if (s->size == s->cap) {
            s->cap *= 2;
            s->res = realloc(s->res, s->cap * sizeof(int));
        }

        s->res[s->size++] = v;
    }
}

static void inorder(struct TreeNode* node, State* s) {
    if (node == NULL) {
        return;
    }

    inorder(node->left, s);
    visit(s, node->val);
    inorder(node->right, s);
}

int* solution2(struct TreeNode* root, int* returnSize) {
    State s = {
        .cur = 0,
        .max = 0,
        .hasPrev = false,
        .res = malloc(4 * sizeof(int)),
        .size = 0,
        .cap = 4
    };

    inorder(root, &s);

    *returnSize = s.size;
    return s.res;
}

/**
 * Solution 3
 * 
 * Morris In-order Traversal + Running Count
 * 
 * Complexities:
 *   n - The Number of Nodes in `root`
 *   h - The Height of `root`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(h)
 */
int* solution3(struct TreeNode* root, int* returnSize) {
    State s = {
        .cur = 0,
        .max = 0,
        .hasPrev = false,
        .res = malloc(4 * sizeof(int)),
        .size = 0,
        .cap = 4
    };

    struct TreeNode* cur = root;
    while (cur != NULL) {
        if (cur->left == NULL) {
            visit(&s, cur->val);
            cur = cur->right;
            continue;
        }

        struct TreeNode* pre = cur->left;
        while (pre->right != NULL && pre->right != cur) {
            pre = pre->right;
        }

        if (pre->right == NULL) {
            pre->right = cur;
            cur = cur->left;
        } else {
            pre->right = NULL;
            visit(&s, cur->val);
            cur = cur->right;
        }
    }

    *returnSize = s.size;
    return s.res;
}
