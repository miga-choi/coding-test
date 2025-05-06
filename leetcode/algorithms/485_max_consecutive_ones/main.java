class MaxConsecutiveOnes {
    public int findMaxConsecutiveOnes(int[] nums) {
        int result = 0;
        int curr = 0;

        for (int num : nums) {
            if (num == 1) {
                curr++;
            } else {
                if (curr > result) {
                    result = curr;
                }
                curr = 0;
            }
        }

        return Math.max(result, curr);
    }


    // Solution
    public int solution(int[] nums) {
        int maxHere = 0, max = 0;

        for (int n : nums) {
            max = Math.max(max, maxHere = n == 0 ? 0 : maxHere + 1);
        }

        return max;
    }
}
