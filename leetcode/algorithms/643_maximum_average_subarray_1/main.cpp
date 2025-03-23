#include <algorithm>
#include <vector>
using namespace std;

class MaximumAverageSubarrayI {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0, maxSum = 0;

        for (int i = 0; i < k; i++) {
            currSum += nums[i];
        }
        maxSum = currSum;

        for (int i = k; i < nums.size(); i++) {
            currSum += nums[i] - nums[i - k];
            maxSum = max(currSum, maxSum);
        }

        return maxSum / k;
    }

    // Solution
    double solution(vector<int>& nums, int k) {
        double currSum = 0, maxSum = 0;

        // Initialize currSum and maxSum to the sum of the initial k elements
        for (int i = 0; i < k; i++) {
            currSum += nums[i];
        }
        maxSum = currSum;

        // Start the loop from the kth element
        // Iterate until you reach the end
        for (int i = k; i < nums.size(); i++) {
            // Subtract the left element of the window
            // Add the right element of the window
            currSum += nums[i] - nums[i - k];

            // Update the max
            maxSum = max(maxSum, currSum);
        }

        // Since the problem requires average, we return the average
        return maxSum / k;
    }
};
