class TeemoAttacking {
    /**
     * Single Pass (Interval Gap Comparison)
     * 
     * Complexities:
     *   n - The Size of `timeSeries`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int result = 0;

        for (int i = 1; i < timeSeries.length; i++) {
            if (timeSeries[i] - timeSeries[i - 1] >= duration) {
                result += duration;
            } else {
                result += timeSeries[i] - timeSeries[i - 1];
            }
        }

        result += duration;

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Single Pass (Interval Gap Comparison)
     * 
     * Complexities:
     *   n - The Size of `timeSeries`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    public int solution1(int[] timeSeries, int duration) {
        if (timeSeries.length == 0) {
            return 0;
        }

        int total = 0;
        for (int i = 0; i < timeSeries.length - 1; i++) {
            total += Math.min(timeSeries[i + 1] - timeSeries[i], duration);
        }

        return total + duration;
    }

    /**
     * Solution 2
     * 
     * Single Pass (End Time Tracking)
     * 
     * Complexities:
     *   n - The Size of `timeSeries`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    public int solution2(int[] timeSeries, int duration) {
        int total = 0, end = 0;

        for (int t : timeSeries) {
            if (t >= end) {
                total += duration;
            } else {
                total += t + duration - end;
            }

            end = t + duration;
        }

        return total;
    }
}
