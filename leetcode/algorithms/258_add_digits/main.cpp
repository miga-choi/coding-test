class AddDigits {
public:
    int addDigits(int num) {
        int sum = num;

        while (sum >= 10) {
            sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            num = sum;
        }

        return sum;
    }


    // Solution
    /**
     * Solution 1
     *
     * Digital Root
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    int solution1(int num) {
        if (num == 0) {
            return 0;
        }

        return (num - 1) % 9 + 1;
    }

    /**
     * Solution 2
     *
     * Iterative
     *
     * Complexities:
     *   - Time Complexity: O(log₁₀ᴺ)
     *   - Space Complexity: O(1)
     */
    int solution2(int num) {
        while (num >= 10) {
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            num = sum;
        }

        return num;
    }
};
