#include <stdbool.h>
#include <stdlib.h>
#include "uthash.h"

bool containsDuplicate(int* nums, int numsSize) {
}


// Solution
/**
 * Sorting
 * 
 * Complexities:
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(1)
 */
int compare(const void* a, const void* b) {
    int valA = *(const int*)a;
    int valB = *(const int*)b;

    if (valA < valB) {
        return -1;
    }
    if (valA > valB) {
        return 1;
    }

    return 0;
}

bool solution1(int* nums, int numsSize) {
    if (numsSize <= 1) return false;

    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}

/**
 * Solution 2
 * 
 * Hash Table
 * 
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
struct hash_entry {
    int id;
    UT_hash_handle hh;
};

bool solution2(int* nums, int numsSize) {
    struct hash_entry *hashTable = NULL;
    struct hash_entry *element;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hashTable, &nums[i], element);
        
        if (element != NULL) {
            struct hash_entry *current, *tmp;
            HASH_ITER(hh, hashTable, current, tmp) {
                HASH_DEL(hashTable, current);
                free(current);
            }
            return true;
        }

        element = (struct hash_entry*)malloc(sizeof(struct hash_entry));
        element->id = nums[i];
        HASH_ADD_INT(hashTable, id, element);
    }

    struct hash_entry *current, *tmp;
    HASH_ITER(hh, hashTable, current, tmp) {
        HASH_DEL(hashTable, current);
        free(current);
    }

    return false;
}
