void moveZeroes(int* nums, int numsSize) {
    int newNums[numsSize];
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i]) {
            newNums[count++] = nums[i];
        }
    }

    for (int i = 0; i < count; i++) {
        nums[i] = newNums[i];
    }

    for (int i = 1; i <= numsSize - count; i++) {
        nums[numsSize - i] = 0;
    }
}


// Solution
// Solution 1
void solution1(int* nums, int numsSize) {
    int j = 0;

    // move all the non-zero elements advance
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }

    for (; j < numsSize; j++) {
        nums[j] = 0;
    }
}

// Solution 2
void solution2(int* nums, int numsSize) {
    int slow = 0;
    int fast = 0;
    while (fast < numsSize) {
        if (nums[fast] != 0) {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    for (int i = slow; i < numsSize; i++) {
        nums[i] = 0;
    }
}
