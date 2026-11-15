#include <cmath>  // std::sqrt
#include <vector> // std::vector
using namespace std;

class ConstructTheRectangle {
public:
    /**
     * Divisor Search from 1 Upward
     *
     * Complexities:
     *   n - `area`
     *   - Time Complexity: O(√n)
     *   - Space Complexity: O(√n)
     */
    vector<int> constructRectangle(int area) {
        vector<int> result = {area, 1};
        int diff = area;

        for (int i = 1; i <= sqrt(area); i++) {
            if (!(area % i)) {
                if (area / i - i < diff) {
                    result[0] = area / i;
                    result[1] = i;
                }
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Divisor Search from √area Downward
     *
     * Complexities:
     *   n - `area`
     *   - Time Complexity: O(√n)
     *   - Space Complexity: O(1)
     */
    vector<int> solution1(int area) {
        int w = static_cast<int>(sqrt(static_cast<double>(area)));

        while (w * w > area) {
            --w;
        }

        while ((w + 1) * (w + 1) <= area) {
            ++w;
        }

        while (area % w != 0) {
            --w;
        }

        return {area / w, w};
    }

    /**
     * Solution 2
     * 
     * Divisor Search from 1 Upward
     *
     * Complexities:
     *   n - `area`
     *   - Time Complexity: O(√n)
     *   - Space Complexity: O(√n)
     */
    vector<int> solution2(int area) {
        int best = 1;

        for (int w = 1; w * w <= area; ++w) {
            if (area % w == 0) {
                best = w;
            }
        }

        return {area / best, best};
    }

};
