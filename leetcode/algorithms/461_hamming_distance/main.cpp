#include <bit>    // std::popcount
#include <bitset> // std::bitset::count
using namespace std;

class HammingDistance {
public:
    /**
     * Math
     *
     * Complexities:
     *   M - `x`
     *   N - `y`
     *   - Time Complexity: O(logᵐᵃˣ⁽ᴹ˒ᴺ⁾)
     *   - Space Complexity: O(1)
     */
    int hammingDistance(int x, int y) {
        int cnt = 0, n = x ^ y;

        while (n) {
            cnt += n & 1;
            n >>= 1;
        }

        return cnt;
    }


    // Solution
    /**
     * Solution 1
     *
     * Bit Manipulation (XOR + Bit-by-bit Shift)
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    int solution1(int x, int y) {
        auto d = static_cast<unsigned int>(x ^ y);
        int count = 0;

        while (d != 0) {
            count += d & 1;
            d >>= 1;
        }

        return count;
    }

    /**
     * Solution 2
     *
     * Bit Manipulation (XOR + Brian Kernighan’s Algorithm)
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    int solution2(int x, int y) {
        auto d = static_cast<unsigned int>(x ^ y);
        int count = 0;

        while (d != 0) {
            d &= d - 1;
            ++count;
        }

        return count;
    }

    /**
     * Solution 3
     *
     * std::Popcount (C++20)
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    int solution3(int x, int y) {
        return popcount(static_cast<unsigned int>(x ^ y));
    }

    /**
     * Solution 4
     *
     * std::bitset::count (C++98)
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    int solution4(int x, int y) {
        return static_cast<int>(bitset<32>(x ^ y).count());
    }
};
