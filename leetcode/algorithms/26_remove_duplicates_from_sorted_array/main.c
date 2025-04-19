int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int j = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[j - 1]) {
            nums[j] = nums[i];
            j++;
        }
    }

    return j;
}


// Solution
// Solution 1:
int solution1(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    // Initialize the count of unique elements to 1
    int k = 1; 

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[k - 1]) {
            // Overwrite the next unique element
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

// Solution 2:
int solution2(int* nums, int numsSize) {
    int new_size = numsSize;
    for (int idx = 0, i = 0, j = 1; i < numsSize; idx++, j++) {
        while (j < numsSize && nums[i] == nums[j]) {
            j++;
            new_size--;
        }
        nums[idx] = nums[j - 1];
        i = j;
    }
    return new_size;
}
