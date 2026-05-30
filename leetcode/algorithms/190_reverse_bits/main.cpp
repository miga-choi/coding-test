#include <stdint.h>

class ReverseBits {
public:
    /**
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; i++) {
            result = result << 1;
            result = result | (n & 1);
            n = n >> 1;
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    uint32_t solution1(uint32_t n) {
        uint32_t result = 0;

        for (int i = 0; i < 32; ++i) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }

        return result;
    }

    /**
     * Solution 2
     *
     * Bit Hack
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    uint32_t solution2(uint32_t n) {
        n = ((n >> 16) & 0x0000FFFF) | ((n << 16) & 0xFFFF0000);
        
        n = ((n >> 8) & 0x00FF00FF) | ((n << 8) & 0xFF00FF00);
        
        n = ((n >> 4) & 0x0F0F0F0F) | ((n << 4) & 0xF0F0F0F0);
        
        n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xCCCCCCCC);
        
        n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xAAAAAAAA);
        
        return n;
    }
};
