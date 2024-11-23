int missingNumber(int *nums, int numsSize) {
    int sum = 0;
    int originSum = 0;
    for (int i = 0; i <= numsSize; i++) {
        originSum += i;
        if (i < numsSize) {
            sum += nums[i];
        }
    }
    return originSum - sum;
}

// Best Solution 1: Naive Approach - Sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int bestSolution1(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i) {
            return i;
        }
    }
    return numsSize;
}

// Best Solution 2: Mathematical Formula
int bestSolution2(int *nums, int numsSize) {
    int sum = numsSize * (numsSize + 1) / 2;
    for (int i = 0; i < numsSize; i++) {
        sum -= nums[i];
    }
    return sum;
}

// Best Solution 3: Bit Manipulation (XOR)
int bestSolution3(int *nums, int numsSize) {
    int missing = 0;
    for (int i = 0; i < numsSize; i++) {
        missing ^= i ^ nums[i];
    }
    missing ^= numsSize;
    return missing;
}

// Best Solution 4: Hash Table
int bestSolution4(int *nums, int numsSize) {
    int hashTable[numsSize + 1];
    memset(hashTable, 0, sizeof(hashTable));
    for (int i = 0; i < numsSize; i++) {
        hashTable[nums[i]] = 1;
    }
    for (int i = 0; i < numsSize + 1; i++) {
        if (hashTable[i] == 0) {
            return i;
        }
    }
    return -1;
}
