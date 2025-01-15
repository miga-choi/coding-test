int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max = 0;
    int current = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            current++;
            if (current > max) {
                max = current;
            }
        } else {
            current = 0;
        }
    }

    return max;
}

// Best Solution
int bestSolution(int* nums, int numsSize) {
    int max_cnt = 0, cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            max_cnt = max_cnt > ++cnt ? max_cnt : cnt;
        } else {
            cnt = 0;
        }
    }
    return max_cnt;
}
