#include <stdbool.h>
#include <stdlib.h>

bool containsDuplicate(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}


// Solution
// Solution 1: in-house HashSet
struct Node {
    int val;
    struct Node* next;
};

struct Set {
    int bucketSize;
    struct Node** table;
};

void initSet(struct Set* set, int bucketSize) {
    set->bucketSize = bucketSize;
    set->table = malloc(sizeof(struct Node*) * bucketSize);
    memset(set->table, 0, sizeof(struct Node*) * bucketSize);
}

bool addValue(struct Set* s, int val) {
    int idx = val > 0 ? val : -val;
    idx %= s->bucketSize;
    struct Node* ptr = s->table[idx];
    while (ptr != NULL) {
        if (ptr->val == val) {
            return false;
        }
        ptr = ptr->next;
    }
    ptr = malloc(sizeof(struct Node));
    ptr->val = val;
    ptr->next = s->table[idx];
    s->table[idx] = ptr;
    return true;
}

void releaseSet(struct Set* s) {
    struct Node* ptr, *tmp;
    for (int i = 0; i < s->bucketSize; ++i) {
        ptr = s->table[i];
        while (ptr != NULL) {
            tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }
    free(s->table);
    s->table = NULL;
    s->bucketSize = 0;
}

bool solution1(int* nums, int numsSize) {
    if (numsSize < 2) {
        return false;
    }

    struct Set set;
    initSet(&set, numsSize / 2);
    for (int i = 0; i < numsSize; ++i) {
        if (!addValue(&set, nums[i])) {
            releaseSet(&set);
            return true;
        }
    }

    releaseSet(&set);
    return false;
}

// Solution 2: Sort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool solution2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }

    return false;
}

// Solution 3: Hash table
typedef struct hashlist {
    int val;
    struct hashlist *next;
} list;

int solution3(int* nums, int numsSize) {
    int i;
    int mask = numsSize - 1;

    list *tmp[numsSize];
    memset(tmp, 0, sizeof(list *) * numsSize);

    if (numsSize == 0 || numsSize == 1) {
        return false;
    }

    for (i = 0; i < numsSize; i++) {
        int idx;
        list *p;
        list *node = malloc(sizeof(list));
        node->val = *nums;
        idx = abs(*nums) % mask;
        p = tmp[idx];
        node->next = p;
        tmp[idx] = node;
        while (p) {
            if (p->val == node->val) {
                return true;
            }
            p = p->next;
        }
        nums++;
    }

    return false;
}
