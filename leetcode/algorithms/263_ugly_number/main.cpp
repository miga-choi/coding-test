#include <initializer_list>
using namespace std;

class UglyNumber {
public:
    /**
     * Iterative Division
     *
     * Complexities:
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(N)
     */
    bool isUgly(int n) {
        while (n) {
            if (!(n % 5)) {
                n /= 5;
            } else if (!(n % 3)) {
                n /= 3;
            } else if (!(n % 2)) {
                n /= 2;
            } else {
                if (!n || n == 1 || n == 2 || n == 3 || n == 5) {
                    return true;
                } else {
                    break;
                }
            }
        }
        return false;
    }


    // Solution
    /**
     * Iterative Division
     *
     * Complexities:
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(N)
     */
    bool solution(int n) {
        if (n <= 0) {
            return false;
        }

        for (int factor : {2, 3, 5}) {
            while (n % factor == 0) {
                n /= factor;
            }
        }

        return n == 1;
    }
};
