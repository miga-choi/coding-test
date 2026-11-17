#include <algorithm>  // std::min
#include <cstddef>    // std::size_t
#include <functional> // std::plus
#include <numeric>    // std::transform_reduce (C++17)
#include <vector>     // std::vector
using namespace std;

class TeemoAttacking {
public:
    /**
     * Single Pass + Pairwise Gap
     *
     * Complexities:
     *   n - The Size of `timeSeries`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;

        for (int i = 1; i < timeSeries.size(); i++) {
            if (timeSeries.at(i) > timeSeries.at(i - 1) + duration) {
                total += duration;
            } else {
                total += timeSeries.at(i) - timeSeries.at(i - 1);
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
     *   n - The Size of `timeSeries`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    int solution1(vector<int>& timeSeries, int duration) {
        int total = 0;

        for (size_t i = 0; i + 1 < timeSeries.size(); ++i) {
            total += min(timeSeries[i + 1] - timeSeries[i], duration);
        }

        return total + duration;
    }

    /**
     * Solution 2
     *
     * Interval Union with End Tracking
     *
     * Complexities:
     *   n - The Size of `timeSeries`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    int solution2(vector<int>& timeSeries, int duration) {
        int total = 0, end = 0;

        for (int t : timeSeries) {
            int start = std::max(t, end);
            total += (t + duration) - start;
            end = t + duration;
        }

        return total;
    }

    /**
     * Solution 3
     *
     * std::transform_reduce over Adjacent Pairs
     *
     * Complexities:
     *   n - The Size of `timeSeries`
     *   - Time Complexity: O(n)
     *   - Space Complexity: O(1)
     */
    int solution3(vector<int>& timeSeries, int duration) {
        int total = transform_reduce(
            timeSeries.begin(),
            timeSeries.end() - 1,
            timeSeries.begin() + 1,
            0,
            plus<>(),
            [duration](int a, int b)
            { return min(b - a, duration); }
        );

        return total + duration;
    }
};
