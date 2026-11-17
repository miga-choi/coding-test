/**
 * Single Pass + Pairwise Gap
 * 
 * Complexities:
 *   n - `timeSeriesSize`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int total = 0;

    for (int i = 1; i < timeSeriesSize; i++) {
        if (timeSeries[i] > timeSeries[i - 1] + duration) {
            total += duration;
        } else {
            total += timeSeries[i] - timeSeries[i - 1];
        }
    }

    return total + duration;
}


// Solution
/**
 * Solution 1
 * 
 * Single Pass + Pairwise Gap
 * 
 * Complexities:
 *   n - `timeSeriesSize`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
int solution1(int* timeSeries, int timeSeriesSize, int duration) {
    int total = 0;

    for (int i = 0; i + 1 < timeSeriesSize; i++) {
        int gap = timeSeries[i + 1] - timeSeries[i];
        total += gap < duration ? gap : duration;
    }

    return total + duration;
}

/**
 * Solution 2
 * 
 * Interval Union with End Tracking
 * 
 * Complexities:
 *   n - `timeSeriesSize`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
int solution2(int* timeSeries, int timeSeriesSize, int duration) {
    int total = 0, end = 0;

    for (int i = 0; i < timeSeriesSize; i++) {
        int start = timeSeries[i] > end ? timeSeries[i] : end;
        int newEnd = timeSeries[i] + duration;
        total += newEnd - start;
        end = newEnd;
    }

    return total;
}
