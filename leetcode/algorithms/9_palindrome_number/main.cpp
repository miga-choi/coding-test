class PalindromeNumber {
public:
    /**
     * Complexities:
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int origin = x;
        long reverse = 0;
        while (x > 0) {
            int res = x % 10;
            x /= 10;
            reverse = reverse * 10 + res;
        }

        return reverse == origin;
    }


    // Solution
    /**
     * Complexities:
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    bool solution(int x) {
        if (x < 0) {
            return false;
        }

        long long reversed = 0;
        int temp = x;

        while (temp > 0) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        return x == reversed;
    }
};
