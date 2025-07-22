#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Brute-Force
 * - Time Complexity: O(N²)
 * - Space Complexity: O(1)
 */
int* twoSum1(int* nums, int numsSize, int target, int* returnSize) {
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

/**
 * Hash Map
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 */
 typedef struct Ht_Entry {
    int key;
    int value;
    struct Ht_Entry* next;
} Ht_Entry;

typedef struct IntHashMap {
    Ht_Entry** buckets;
    size_t capacity;
    size_t count;
} IntHashMap;

static unsigned long hash_function(unsigned long key) {
    unsigned int c2 = 0x27d4eb2d;
    key = (key ^ 61) ^ (key >> 16);
    key = key + (key << 3);
    key = key ^ (key >> 4);
    key = key * c2;
    key = key ^ (key >> 15);
    return (unsigned long)key;
}

IntHashMap* ihm_create(size_t capacity) {
    IntHashMap* map = (IntHashMap*)malloc(sizeof(IntHashMap));
    if (map == NULL) {
        return NULL;
    }

    map->capacity = capacity;
    map->count = 0;

    map->buckets = (Ht_Entry**)calloc(map->capacity, sizeof(Ht_Entry*));
    if (map->buckets == NULL) {
        free(map);
        return NULL;
    }

    return map;
}

void ihm_destroy(IntHashMap* map) {
    if (map == NULL) {
        return;
    }

    for (size_t i = 0; i < map->capacity; i++) {
        Ht_Entry* entry = map->buckets[i];
        while (entry != NULL) {
            Ht_Entry* next_entry = entry->next;
            free(entry);
            entry = next_entry;
        }
    }

    free(map->buckets);
    free(map);
}

void ihm_set(IntHashMap* map, const int key, const int value) {
    if (map == NULL) {
        return;
    }

    unsigned long hash = hash_function(key);
    size_t index = hash % map->capacity;

    Ht_Entry* entry = map->buckets[index];
    while (entry != NULL) {
        if (entry->key == key) {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }

    Ht_Entry* new_entry = (Ht_Entry*)malloc(sizeof(Ht_Entry));
    if (new_entry == NULL) {
        return;
    }

    new_entry->key = key;
    new_entry->value = value;

    new_entry->next = map->buckets[index];
    map->buckets[index] = new_entry;
    map->count++;
}

int ihm_get(IntHashMap* map, int key) {
    if (map == NULL) {
        return -1;
    }

    unsigned long hash = hash_function(key);
    size_t index = hash % map->capacity;

    Ht_Entry* entry = map->buckets[index];
    while (entry != NULL) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }

    return -1;
}

int* twoSum2(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    IntHashMap* map = ihm_create(numsSize);

    for (int i = 0; i < numsSize; i++) {
        int index = ihm_get(map, target - nums[i]);

        if (index >= 0) {
            result[0] = index;
            result[1] = i;
            *returnSize = 2;
            break;
        }

        ihm_set(map, nums[i], i);
    }

    ihm_destroy(map);

    return result;
}
