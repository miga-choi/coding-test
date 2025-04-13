int findLengthOfLCIS(int* nums, int numsSize) {
    int count = 1;
    int longest = 1;
    int prev = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > prev) {
            count++;
            if (count > longest) {
                longest = count;
            }
        } else {
            count = 1;
        }
        prev = nums[i];
    }

    return longest;
}

// Solution
int solution(int* nums, int numsSize) {
    int res = 0, cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i == 0 || nums[i - 1] < nums[i]) {
            cnt++;
            if (cnt > res) {
                res = cnt;
            }
        } else {
            cnt = 1;
        }
    }
    return res;
}
