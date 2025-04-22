#include <stdlib.h>
#include <stdbool.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j] && abs(i - j) <= k) {
                return true;
            }
        }
    }
    return false;
}


// Solution
struct HashNode {
    int key;
    int value;
    struct HashNode* next;
};

bool solution(int* nums, int numsSize, int k) {
    struct HashNode** hashMap = (struct HashNode**)calloc(numsSize, sizeof(struct HashNode*));

    for (int i = 0; i < numsSize; ++i) {
        int currentNum = nums[i];
        int hashIndex = abs(currentNum) % numsSize;

        struct HashNode* node = hashMap[hashIndex];
        while (node) {
            if (node->key == currentNum) {
                if (i - node->value <= k) {
                    free(hashMap);
                    return true;
                } else {
                    node->value = i;
                    break;
                }
            }
            node = node->next;
        }

        if (!node) {
            node = (struct HashNode*)malloc(sizeof(struct HashNode));
            node->key = currentNum;
            node->value = i;
            node->next = hashMap[hashIndex];
            hashMap[hashIndex] = node;
        }
    }

    free(hashMap);
    return false;
}
