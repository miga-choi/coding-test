#include "uthash/uthash.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Brute-Force
 * 
 * Complexities:
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    return result;
}


// Solution
/**
 * Solution 1
 * 
 * Brute-Force
 * 
 * Complexities:
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
int* solution1(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    
    *returnSize = 0;
    return NULL;
}

/**
 * Solution 2
 * 
 * Hash Map
 * 
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
struct hashTable {
    int key;
    int value;
    UT_hash_handle hh;
};

int* solution2(int* nums, int numsSize, int target, int* returnSize) {
    struct hashTable *users = NULL;
    struct hashTable *item = NULL;
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        HASH_FIND_INT(users, &complement, item);
        
        if (item != NULL) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = item->value;
            result[1] = i;
            *returnSize = 2;
            
            struct hashTable *current, *tmp;
            HASH_ITER(hh, users, current, tmp) {
                HASH_DEL(users, current);
                free(current);
            }
            
            return result;
        }
        
        item = (struct hashTable*)malloc(sizeof(struct hashTable));
        item->key = nums[i];
        item->value = i;
        HASH_ADD_INT(users, key, item);
    }
    
    *returnSize = 0;
    return NULL;
}
