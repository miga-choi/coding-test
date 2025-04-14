class LongestContinuousIncreasingSubsequence {
    public int findLengthOfLCIS(int[] nums) {
        int res = 1, count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) {
                count++;
                if (count > res) {
                    res = count;
                }
            } else {
                count = 1;
            }
        }
        return res;
    }

    // Solution
    public int solution(int[] nums) {
        int res = 0, cnt = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i == 0 || nums[i - 1] < nums[i]) {
                res = Math.max(res, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return res;
    }
}
