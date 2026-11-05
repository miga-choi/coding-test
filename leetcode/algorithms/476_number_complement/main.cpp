#include <bit>     // std::bit_width (C++20)
#include <cstdint> // std::uint32_t
using namespace std;

class NumberComplement {
public:
    /**
     * Left-Shifting Inverted Mask + XOR
     *
     * Complexities:
     *   N - `num`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    int findComplement(int num) {
        unsigned int mask = ~0;

        while (mask & num) {
            mask <<= 1;
        }

        return ~mask ^ num;
    }


    // Solution
    /**
     * Solution 1
     *
     * Bit-by-bit Flip
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    int solution1(int num) {
        auto n = static_cast<unsigned int>(num);
        unsigned int res = 0;

        for (int pos = 0; n != 0; ++pos, n >>= 1) {
            res |= ((n & 1u) ^ 1u) << pos;
        }

        return static_cast<int>(res);
    }

    /**
     * Solution 2
     *
     * Bit Mask Construction + XOR
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    int solution2(int num) {
        auto n = static_cast<unsigned int>(num);
        unsigned int mask = 1;

        while (mask < n) {
            mask = (mask << 1) | 1u;
        }

        return static_cast<int>(mask ^ n);
    }

    /**
     * Solution 3
     *
     * Bit Smearing + XOR
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    int solution3(int num) {
        auto n = static_cast<uint32_t>(num);
        uint32_t mask = n;

        mask |= mask >> 1;
        mask |= mask >> 2;
        mask |= mask >> 4;
        mask |= mask >> 8;
        mask |= mask >> 16;

        return static_cast<int>(mask ^ n);
    }

    /**
     * Solution 4
     *
     * Bit Width (Standard Library) + XOR
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    int solution4(int num) {
        auto n = static_cast<unsigned int>(num);
        unsigned int mask = (1u << bit_width(n)) - 1u;

        return static_cast<int>(mask ^ n);
    }
};
